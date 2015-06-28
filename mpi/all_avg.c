#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#include <assert.h>

float *create_rand_nums(int num_elements)
{
	float *rand_nums = (float *)malloc(sizeof(float) * num_elements);
	if (rand_nums == NULL) {
		fprintf(stderr, "memory not enough.\n");
		exit(-1);
	}
	for (int i = 0; i < num_elements; i++) {
		rand_nums[i] = (rand() / (float)RAND_MAX);
	}
	return rand_nums;
}

float compute_avg(float *array, int num_elements)
{
	float sum = 0;
	for (int i = 0; i < num_elements; i++) {
		sum += array[i];
	}
	return sum / num_elements;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: avg num_elements_per_proc\n");
		exit(-1);
	}
	int num_elements_per_proc = atoi(argv[1]);
	srand(time(NULL));
	MPI_Init(NULL, NULL);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	float *rand_nums = NULL;
	if (world_rank == 0) {
		rand_nums = create_rand_nums(num_elements_per_proc * world_size);
	}

	float *sub_rand_nums = (float *)malloc(sizeof(float) * num_elements_per_proc);
	if (sub_rand_nums == NULL) {
		fprintf(stderr, "memory not enough.\n");
		exit(-1);
	}

	MPI_Scatter(rand_nums, num_elements_per_proc, MPI_FLOAT, sub_rand_nums,
			num_elements_per_proc, MPI_FLOAT, 0, MPI_COMM_WORLD);

	float sub_avg = compute_avg(sub_rand_nums, num_elements_per_proc);
	float *sub_avgs = NULL;
	sub_avgs = (float *)malloc(sizeof(float) * world_size);
	if (sub_avgs == NULL) {
		fprintf(stderr, "memory not enough.\n");
		exit(-1);
	}
	MPI_Allgather(&sub_avg, 1, MPI_FLOAT, sub_avgs, 1, MPI_FLOAT, MPI_COMM_WORLD);

	float avg = compute_avg(sub_avgs, world_size);
	printf("Avg of all elements from proc %d is %f\n",world_rank, avg);
	if (world_rank == 0) {
		float orig_avg = compute_avg(rand_nums, num_elements_per_proc * world_size);
		printf("ori_avg is %f\n", orig_avg);
	}

	if (world_rank == 0) {
		free(rand_nums);
	}
	free(sub_avgs);
	free(sub_rand_nums);

	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();

	return 0;
}
