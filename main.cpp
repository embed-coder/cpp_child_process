#include <sys/wait.h>
#include <cstdio>
#include <unistd.h>

/*
* @param[out] Exit status number of Child process
*
* @return     PID of Child process or -1 if error.
*/
pid_t wait(int *status);

int main(int argc, char const *argv[]) {
    pid_t child_pid;
    int status, rv;

    child_pid = fork();
    if (child_pid >= 0) {
        if (0 == child_pid) {       /* Child process*/
            printf("Im the child process, my PID: %d\n", getpid());
            sleep(10);
        } else {                     /* Parent process*/
            printf("\nI'm the parent process, waiting for exit signal from Child process\n");
            rv = wait(&status);
            if (rv == -1) {
                printf("wait() unsuccessful\n");
            }

            printf("\nIm the parent process, PID child process: %d\n", rv);
            
            if (WIFEXITED(status)) {
                printf("Normally termination, status=%d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("killed by signal, value = %d\n", WTERMSIG(status));
            } 
        }
    } else {
        printf("fork() unsuccessfully\n");      // fork() return -1 if error.
    }

    return 0;
}
