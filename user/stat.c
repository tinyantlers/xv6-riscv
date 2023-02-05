// alexis ugalde
// cs 370 
// project 2a
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main()
{
    printf("Process PID: ");
    printf("%d\n",getpid());

	printf("Memory Used: ");
    printf("%d\n",getmem());	

    printf("Proc State: ");
    int process = getstate();

    if(process == 0)
        printf("UNUSED\n");
    if(process == 1)
        printf("USED\n");
    if(process == 2)
        printf("SLEEPING\n");
    if(process == 3)
        printf("RUNNABLE\n");
    if(process == 4)
        printf("RUNNING\n");
    if(process == 5)
        printf("ZOMBIE\n");

    printf("Uptime(ticks): ");
    printf("%d\n",uptime());

	printf("Parent PID: ");
    printf("%d\n",getparentpid());

	printf("Page Tble Addr: ");
    printf("%x\n",getkstack());

	exit(0);

}
