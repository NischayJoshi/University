#include <stdio.h>
#include <stdlib.h>

struct process
{
  int pid;
  int at, bt, st, ct, rt, tat, wt;
} P[50];

int comparator_PID(const void *P1, const void *P2)
{
  int a = ((struct process *)P1)->pid;
  int b = ((struct process *)P2)->pid;
  return a - b;
}

int comparator_AT(const void *P1, const void *P2)
{
  int a = ((struct process *)P1)->at;
  int b = ((struct process *)P2)->at;
  if (a == b)
    return comparator_PID(P1, P2);
  else
    return a - b;
}

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
  }

  qsort(P, n, sizeof(struct process), comparator_AT);

  int current_time = 0;
  int total_tat = 0, total_wt = 0;
  for (int i = 0; i < n; i++)
  {
    P[i].st = current_time > P[i].at ? current_time : P[i].at;
    P[i].ct = P[i].st + P[i].bt;
    P[i].rt = P[i].st - P[i].at;
    P[i].tat = P[i].ct - P[i].at;
    P[i].wt = P[i].tat - P[i].bt;
    total_tat += P[i].tat;
    total_wt += P[i].wt;
    current_time = P[i].ct;
  }

  qsort(P, n, sizeof(struct process), comparator_PID);

  printf("\n\nPID\tAT\tBT\tST\tCT\tRT\tTAT\tWT\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", P[i].pid, P[i].at, P[i].bt, P[i].st, P[i].ct, P[i].rt, P[i].tat, P[i].wt);
  }
  printf("Average turn around time = %f\n", (float)total_tat / n);
  printf("Average waiting time = %f\n", (float)total_wt / n);

  return 0;
}