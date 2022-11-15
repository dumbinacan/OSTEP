#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    int rc = fork();
    char *p3[] = {"./p3", NULL};//I'm lazy and hate double work
    if (rc < 0) {// fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if (rc == 0) { //child
        close(STDOUT_FILENO);// below here the book copy and pastes p3
        open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        execvp(p3[0], p3);
    }else { //parent
        int rc_wait = wait(NULL);
    }
    return 0;
}
