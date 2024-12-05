#include <stdio.h>
#include <unistd.h>

int main()
{
  pid_t pid = fork();
  if (pid == -1)
  {
    printf("Forking failed.\n");
  }
  else if (pid == 0)
  {
    printf("This is the child with pid: %d\n", pid);
  }
  else
  {
    printf("This is the parent with pid: %d\n", pid);
  }
  return 0;
}