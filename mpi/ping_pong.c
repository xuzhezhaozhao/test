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

	int ping_pong_count = 0;
	int partner_rank = 1 - world_rank;
	while ( ping_pong_count < 10 ) {
		if (world_rank == ping_pong_count % 2) {
			ping_pong_count++;
			MPI_Send(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD);
			printf("%d send and incrented ping_pong_count %d to %d\n", 
					world_rank, ping_pong_count, partner_rank);
		} else {
			MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("%d received ping_pong_count %d from %d\n", 
					world_rank, ping_pong_count, partner_rank);
		}
	}

	MPI_Finalize();

	return 0;
}
