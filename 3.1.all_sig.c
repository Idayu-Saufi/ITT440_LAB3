#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>


int main(void)
{


  void sigint_handler(int sigint);
  void sigtstp_handler(int sigtstp);
  void sigquit_handler(int sigquit);
  char c[200];
  char z[150];
  char q[100];


  if(signal(SIGINT,sigint_handler) == SIG_ERR){
    perror("signal c");
    exit(1);
  }
  else if(signal(SIGTSTP,sigtstp_handler) == SIG_ERR){
    perror("signal z");
    exit(1);
  }
  else if (signal(SIGQUIT,sigquit_handler) == SIG_ERR){
    perror("signal /");
    exit(1);
  }

  printf("Enter a string:\n");

  if(fgets(c,200,stdin) == NULL)
    perror("gets");
  else
    printf("you entered: %s\n",c);


  if(fgets(z,150,stdin) == NULL)
    perror("gets");
  else
    printf("you entered: %s\n",z);


  if(fgets(q,100,stdin) == NULL)
    perror("gets");
  else
    printf("you entered: %s\n",q);

  return 0;
}


void sigint_handler(int sigint)
{
  printf("\tThis is a special signal handler for SIGINT\n");
}

void sigtstp_handler(int sigtstp)
{
  printf("\tThis is a special handler for SIGTSTP\n");
}

void sigquit_handler(int sigquit)
{
  printf("\tThis is a special handler for SIGQUIT\n");
}


