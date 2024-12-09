#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct process
{
  int pid;
  int at, bt, rbt, st, ct, rt, tat, wt;
} P[50];

int main()
{
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  printf("Enter the arrival time of each process: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &P[i].at);
    P[i].pid = i + 1;
  }

  printf("Enter the burst time of each process: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &P[i].bt);
    P[i].rbt = P[i].bt;
  }

  int current_time = 0, completed = 0, total_tat = 0, total_wt = 0;
  int is_complete[50] = {false};
  while (completed != n)
  {
    int min_index = -1;
    int min_burst = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      if (!is_complete[i] && P[i].at <= current_time)
      {
        if (P[i].rbt < min_burst)
        {
          min_index = i;
          min_burst = P[i].rbt;
        }
        else if (P[i].rbt == min_burst)
        {
          if (P[i].pid < P[min_index].pid)
          {
            min_index = i;
            min_burst = P[i].rbt;
          }
        }
      }
    }
    if (min_index == -1)
      current_time++;
    else
    {
      if (P[min_index].rbt == P[min_index].bt)
      {
        P[min_index].st = current_time;
        P[min_index].rt = current_time - P[min_index].at;
      }
      current_time++;
      P[min_index].rbt--;
      if (P[min_index].rbt == 0)
      {
        P[min_index].ct = current_time;
        P[min_index].tat = current_time - P[min_index].at;
        P[min_index].wt = P[min_index].tat - P[min_index].bt;
        total_tat += P[min_index].tat;
        total_wt += P[min_index].wt;
        completed++;
        is_complete[min_index] = true;
      }
    }
  }

  printf("\n\nPID\tAT\tBT\tST\tCT\tRT\tTAT\tWT\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", P[i].pid, P[i].at, P[i].bt, P[i].st, P[i].ct, P[i].rt, P[i].tat, P[i].wt);
  }
  printf("Average turn around time = %f\n", (float)total_tat / n);
  printf("Average waiting time = %f\n", (float)total_wt / n);

  return 0;
}