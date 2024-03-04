/*
* Add NetID and names of all project partners
* sk2425 => Sanjay Kethineni
* at1186 => Adhit Thakur
* CS416
* ilab machine used: pascal.cs.rutgers.edu
* shell command to compile: gcc stack.c -o stack -g -m32
* shell command to run: ./stack
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void signal_handle(int signalno) {
    printf("OMG, I was slain!\n");
    
    *(int*)((void*)&signalno+0x3c) += 0x6;
    //exit(1);
}

int main(int argc, char *argv[]) {

    int x=5, y = 0, z=4;

    /* Step 1: Register signal handler first*/
    signal(SIGFPE,signal_handle);

    // This will generate floating point exception
    z=x/y;
    
    printf("LOL, I live again !!!%d\n", z);

    return 0;
} 

 