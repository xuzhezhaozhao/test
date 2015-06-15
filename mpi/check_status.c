#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
	MPI_Init(NULL, NULL);
	int world_rank, world_size;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	if (world_size < 2) {
		fprintf(stderr, "world size must be greated than 1 for %s.\n", argv[0]);
		MPI_Abort(MPI_COMM_WORLD, 1);
	}

	const int MAX_NUMBERS = 100;
	int numbers[MAX_NUMBERS];
	int number_amount;

	if (world_rank == 0) {
		srand(time(NULL));
		number_amount = (rand() / (float)RAND_MAX) * MAX_NUMBERS;
		MPI_Send(numbers, number_amount, MPI_INT, 1, 0, MPI_COMM_WORLD);
	} else if (world_rank == 1) {
		MPI_Status status;
		MPI_Recv(numbers, MAX_NUMBERS, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Get_count(&status, MPI_INT, &number_amount);
		printf("1 received %d numbers from 0. Message source = %d, tag = %d\n",
			number_amount, status.MPI_SOURCE, status.MPI_TAG);
	}


	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();

	return 0;
}
