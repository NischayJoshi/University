#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct process
{
  int max[10];
  int allocated[10];
  int need[10];
} pr[10];

int n, m;

void take_input(struct process pr[n], int available[m])
{
  printf("Enter the maximum needed and already allocated resource to the given process in pair:\n");
  for (int i = 0; i < n; i++)
  {
    // take input of all processes.
  }
}

bool safety_algo(struct process pr[n], int available[m], int safe_sequence[n])
{
  int k = 0;
  bool finished[n];
  for (int i = 0; i < n; i++)
  {
    finished[i] = false;
  }
  bool flag = true;
  while (flag)
  {
    flag = false;

    for (int i = 0; i < n; i++)
    {
      if (finished[i] == true)
        continue;
      int can_be_done = true;
      for (int j = 0; j < m; j++)
      {
        if (pr[i].need[j] > available[j])
        {
          can_be_done = false;
          break;
        }
      }
      if (can_be_done)
      {
        flag = true;
        safe_sequence[k] = i;
        k++;
        for (int j = 0; j < m; j++)
        {
          available[j] += pr[i].allocated[j];
        }
        finished[i] = true;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (finished[i] == false)
    {
      return false;
    }
  }
  return true;
}