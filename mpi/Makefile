EXECS = mpi_hello_world send_recv ping_pong ring check_status probe random_walk \
		avg all_avg reduce_avg reduce_stddev
MPICC ?= mpicc
MPICXX ?= mpicxx

N ?= 4

all: ${EXECS}

test: all
	@echo begin test mpi_hello_world
	mpirun -n $N -f host_file ./mpi_hello_world
	@echo
	@echo begin test send_recv
	mpirun -n $N -f host_file ./send_recv
	@echo
	@echo begin test ping_pong 
	mpirun -n 2 -f host_file ./ping_pong
	@echo
	@echo begin test ring 
	mpirun -n $N -f host_file ./ring
	@echo
	@echo begin test check_status 
	mpirun -n 2 -f host_file ./check_status
	@echo
	@echo begin test probe 
	mpirun -n 2 -f host_file ./probe
	@echo
	@echo begin test random_walk 
	mpirun -n $N -f host_file ./random_walk 100 200 4
	@echo
	@echo begin test avg
	mpirun -n $N -f host_file ./avg 1000
	@echo
	@echo begin test all_avg
	mpirun -n $N -f host_file ./all_avg 1000
	@echo
	@echo begin test reduce_avg
	mpirun -n $N -f host_file ./reduce_avg 1000
	@echo
	@echo begin test reduce_stddev
	mpirun -n $N -f host_file ./reduce_stddev 1000


mpi_hello_world: mpi_hello_world.c
	${MPICC} -o $@ mpi_hello_world.c

send_recv: send_recv.c
	${MPICC} -o $@ send_recv.c

ping_pong: ping_pong.c
	${MPICC} -o $@ ping_pong.c

ring: ring.c
	${MPICC} -o $@ ring.c

check_status: check_status.c
	${MPICC} -o $@ check_status.c

probe: probe.c
	${MPICC} -o $@ probe.c
	
random_walk: random_walk.cpp
	${MPICXX} -o $@ random_walk.cpp

avg: avg.c
	${MPICXX} -o $@ avg.c

all_avg: all_avg.c
	${MPICXX} -o $@ all_avg.c


reduce_avg: reduce_avg.c
	${MPICXX} -o $@ reduce_avg.c

reduce_stddev: reduce_stddev.c
	${MPICXX} -o $@ reduce_stddev.c

clean:
	rm ${EXECS}
