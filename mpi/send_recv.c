#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <unistd.h>

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

	int number;
	if (world_rank == 0) {
		number = 1000;
		MPI_Send(&number, 1, MPI_INT, 1, 10, MPI_COMM_WORLD);
		printf("Process 0 send number %d to process 1\n", number);
	} else if (world_rank == 1) {
		MPI_Recv(&number, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Process 1 received number %d from process 0\n", number);
	}

	MPI_Finalize();

	return 0;
}
