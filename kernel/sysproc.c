#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

// ACTION:  Edit  sysproc.c  to add a function for the new system calls.  
// Do not overthink these functions. You should look at the other system 
// calls definitions to derive your solution.

// Returns memory size of the calling process
uint64
sys_getmem(void)
{
	return myproc()->sz;
}

// Returns the current state (SLEEPING, RUNNING, or RUNNABLE) of the calling processes.
// hint is look at sys_getpid it is linked to proc.h
uint64
sys_getstate(void)
{
  return myproc()->state;
}

// Returns process identification (PID) of the calling process’s parent.
// For getparentpid, it is creating another struct proc so u go into parent then its pid
uint64
sys_getparentpid(void)
{
  return myproc()->parent-> pid;

}

// Returns address of kernel stack.
uint64
sys_getkstack(void)
{
	return myproc() -> kstack;
}
// ------------------------------------------------------------------------
uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
