#include <stdio.h>
#include <signal.h>   /* for sigaction() */
#include <unistd.h>

void myHandler(int signo);

main()
{
    struct sigaction mySignalStruct;
    int fd[2];       

    /* 
     * change the default stdout buffering: don't use any buffering
     */
    if (setvbuf(stdout, NULL, _IONBF, NULL) != 0)
    {
        fprintf(stderr, "setvbuf error\n");
        exit(1);
    }

    /* 
     * setup signal handler: block SIGINT while handler executes
     */ 
    mySignalStruct.sa_handler = myHandler;
    mySignalStruct.sa_flags   = 0;    /* no options being used */

    sigemptyset( &mySignalStruct.sa_mask); 
    sigaddset  ( &mySignalStruct.sa_mask, SIGINT);

    if (sigaction(SIGPIPE, &mySignalStruct, NULL) < 0)
    {
        fprintf(stderr, "sigaction error\n");
        exit(1);
    }

    /* 
     * set up pipe 
     */
    if (pipe(fd) < 0)
    {
        fprintf(stderr, "pipe error\n");
        exit(1);
    }
  
    /*
     * generate SIGPIPE 
     */
    switch ( fork() )
    {
        case -1: /* error */
                 fprintf(stderr, "fork error\n");
                 exit(1);
       
        case 0 : /* child */
                 close(fd[1]);
                 close(fd[0]);  /* closing read end of pipe */
                 exit(0);
 
        default: /* parent */
                 close(fd[0]);
                 write(fd[1], "hello world\n", 12);
    }


    /* 
     * infinite loop 
     */
    printf("Entering infinite loop..\n");
    while (1);  
}

void myHandler(int signo)
{
    int i;

    printf("Caught SIGPIPE.\n");
    printf("    This signal handler will execute for 15 seconds\n");
    printf("    See what happens if you press Ctrl-C (SIGINT) during\n"); 
    printf("    this time...\n");

    for (i = 15; i >= 0; i--)
    {
        printf("%d\n", i);
        sleep(1);
    } 
}

