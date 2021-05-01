#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#define PIN_WAIT_INTERVAL 2

int main(void)
{

  int number, i;
  int buffer;
  int pipefds[2];
  int flag =0;


  if(pipe(pipefds) == -1) 
  {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  pid_t pid = fork();
  if(pid == 0) 
  {
    void sigint_handler(int sig);

      if(signal(SIGINT,sigint_handler) == SIG_ERR) 
      {
        perror("signal");
        exit(1);
      }

    printf("\n\nEnter a Number: ");
    scanf("%d",&number); //ask user to enter number
    close(pipefds[0]); // close child pipe for read
    write(pipefds[1],&number,sizeof(number)); //write number to pipe

    printf("\nSending the number to parent...\n");

    sleep(2); // intentional delay for child process to complete

    exit(EXIT_SUCCESS);
  }

  if(pid > 0) {
    wait(NULL); //wait for child process to finish
    close(pipefds[1]); // close write fd
    read(pipefds[0],&buffer, sizeof(buffer)); //read number from pipe

    printf("Parent received the Number %d from child.\n",buffer);

    for(i =2; i<= buffer/2; ++i) { //condition for non-prime
      if(buffer % i == 0) {
        flag = 1;
        break;
      }
    }

    if(buffer == 1) {
      printf("1 is not a prime number.\n");
    }
    else if(flag == 0) {
      printf("\n%d is a prime number.\n",buffer);
    }
    else {
      printf("\n%d is not a prime number.\n",buffer);
    }

   close(pipefds[0]);
  }

return EXIT_SUCCESS;
}


void sigint_handler(int sig)
{
  printf("\n\n SIGNAL IS INTERRUPT!!! TRY RE - RUN THE CODE AGAIN.. \n");
}

