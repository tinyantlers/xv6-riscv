#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


// implementing the program requires you to use the system call added in the 
// earlier section and other xv6 system calls, in particular fork(), exec(), and wait().

int main(int argc, char * argv[])

{	

	int currentTime = uptime();
	// 1. get current time by using uptime


    // Accepts arguments from the command line interface.  You are expected to do the necessary error checking with appropriate error messages.
    // accepts time plus one more arg ONLY
	if(argc < 2 || argc > 2)
	{
		printf("wrong number of arguments \n");
		exit(0); 
	}
	
	int pid = fork(); 
    // fork a child process

    // you should return an error message if the fork() is unsuccessful.
	if (pid < 0) 
	{
		printf("fork failed\n");
		exit(0);
	}
	
	// child runs cmds
	if(pid == 0) 
	{ 
		exec(argv[1], argv + 1);
		exit(0); 					
	}
			
	// parent process
	if (pid > 0)
	{
		
		// 2. Use the fork() system call and then wait for the child process to terminate.
		wait(0);

        // 3. When use the wait() system call returns to the parent process get the current time again and 
        // calculate the difference.        	
		int realTime = uptime();
		realTime -= currentTime;

		printf("real-time in ticks: %d\n", realTime);
		
	}
	
	exit(0);

}

