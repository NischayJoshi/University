#include <stdio.h>
#include <stdlib.h>

struct process
{
  int pid, at, bt, st, ct, rt, tat, wt;
}pr[100];

int findmax(int a, int b)
{
  return a > b ? a : b;
}

int comparator_pid(const void *a, const void *b)
{
  int x = ((struct process *)a)->pid;
  int y = ((struct process *)b)->pid;
  if (x < y)
    return -1;
  else
    return 1;
}

int comparator_at(const void *a, const void *b)
{
  int x = ((struct process *)a)->at;
  int y = ((struct process *)b)->at;
  if (x < y)
    return -1;
  else if (x == 0)
    return comparator_pid(a, b);
  else
    return 1;
}

int main()
{
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  printf("Enter arrival time and burst time for each process in pair: \n");
  for (int i = 0; i < n;i++)
  {
    pr[i].pid = i;
    scanf("%d", &pr[i].at);
    scanf("%d", &pr[i].bt);
  }

  qsort((void *)pr, n, sizeof(struct process), comparator_at);

  int sum_rt, sum_tat, sum_wt, idle_time;

  for (int i = 0; i < n;i++)
  {
    pr[i].st = (i == 0 ? pr[i].at : findmax(pr[i].at, pr[i - 1].ct));
    pr[i].ct = pr[i].st + pr[i].bt;
    pr[i].rt = pr[i].st - pr[i].at;
    pr[i].tat = pr[i].ct - pr[i].at;
    pr[i].wt = pr[i].tat - pr[i].bt;

    sum_rt = pr[i].rt;
    sum_tat = pr[i].tat;
    sum_wt = pr[i].wt;
    idle_time += (i == 0 ? 0 : (pr[i].st - pr[i - 1].ct));
  }
  int length_cycle = pr[n - 1].ct - pr[0].st;
  float cpu_utilization = ((length_cycle - idle_time) / length_cycle) * 100;
}