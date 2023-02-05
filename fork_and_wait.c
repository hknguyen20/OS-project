/*
The parent program forks a child program, which need to wait and terminate after a given amount of time.
@input:
    int amount: the given seconds that the child needs to wait before exiting
@return::String
    Parent is spawing child.
    Child is waiting for <amount> seconds.
    Child's ID <child>
    Child successfully terminated with exit status <status>
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char **argv)
{
   int amount, status;
   pid_t child, wait;

   if(argc > 1 )
   {
      amount = atoi(argv[1]);
      printf("Parent is pawing child\n");
      child = fork();

      /* Child process */
      if( child == 0 )
      {
         printf("Child is waiting for %d seconds.\n", amount);
         sleep(amount);
         exit(0);
      }
      else
      {

	 status = 0;
	 printf("Children's ID %d.\n", child );
	 wait = waitpid(child, &status, 0);

	 if(WIFEXITED(status))
	    printf("Child successfully terminated with exit status %d\n", WEXITSTATUS(status));


	 if(WIFSIGNALED(status))
	    printf("There must be something wrong: Status %d\n", WTERMSIG(status));
      }
   }
   return(0);
}






syntax highlighted by Code2HTML, v. 0.9
