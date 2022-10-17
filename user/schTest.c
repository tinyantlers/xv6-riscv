
#include "user/user.h"
#include "user/usys.pl"
#include "kernel/syscall.h"
#include "kernel/syscall.c"
#include "kernel/sysproc.c"
#include "kernel/defs.h"
#include "kernel/proc.h"
#include "kernel/proc.c"
#include "kernel/trap.c"

/*
Once the new system call has been added, create a small user-space program that will create a set of 
children using fork().  The children will be used to simulate CPU-bound and I/O bound processes.  The
number of CPU-bound and I/O processes should be defined parameters.

*/

int main()
{
	// numCpuProc =?
	for (int n = 0; n < numCpuProc; n++){
		int cpu_pid = fork();
		if (cpu_pid < 0) 
		{
			printf("fork failed\n");
			exit(0); 
		}
		if (cpu_pid == 0){
			for (volatile int i = 0; i < 1000000000; i++){}
			printf("\nProcess %d finished", n);
			exit(0);
		}

	}
	 
	for (int n =0; n < numIOProc; n++) {
		int io_pid = fork();
		if (io_pid < 0) 
		{
			printf("fork failed\n");
			exit(0); 
		}
		if (io_pid == 0){
			sleep(200);
			printf("\nProcess %d finished", n);
			exit(0);
		}

	}

	
	exit(0);
}
