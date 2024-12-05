// First Come First Serve

#include <stdio.h>
#include <stdlib.h>

struct process_struct
{
  int pid;                         // Process ID
  int at;                          // Arrival Time
  int bt;                          // CPU Burst Time
  int ct, wt, tat, rt, start_time; // Completion, Waiting, Turnaround, Response
};

int findmax(int a, int b)
{
  return a > b ? a : b;
}

int comparatorPID(const void *a, const void *b)
{
  int x = ((struct process_struct *)a)->pid;
  int y = ((struct process_struct *)b)->pid;
  if (x < y)
    return -1; // No Sorting
  else
    return 1; // Sorting
}

int comparatorAT(const void *a, const void *b)
{
  int x = ((struct process_struct *)a)->at;
  int y = ((struct process_struct *)b)->at;

  // Compare based on arrival time
  if (x < y)
    return -1; // No Sorting
  else if (x == y)
  {
    // For same arrival time, compare based on PID
    return comparatorPID(a, b);
  }
  else
    return 1; // Sort
}

int main()
{
  int n;
  printf("Enter total number of processes: ");
  scanf("%d", &n);
  struct process_struct ps[n];

  float sum_tat = 0, sum_wt = 0, sum_rt = 0;
  int length_cycle, total_idle_time = 0;
  float cpu_utilization;

  for (int i = 0; i < n; i++)
  {
    ps[i].pid = i;
    printf("\n Enter Process %d Arrival Time: ", i);
    scanf("%d", &ps[i].at);
    printf("Enter Process %d Burst Time: ", i);
    scanf("%d", &ps[i].bt);
  }

  // Sorting based on arrival time
  qsort((void *)ps, n, sizeof(struct process_struct), comparatorAT);

  // Calculations
  for (int i = 0; i < n; i++)
  {
    ps[i].start_time = (i == 0) ? ps[i].at : findmax(ps[i].at, ps[i - 1].ct);
    ps[i].ct = ps[i].start_time + ps[i].bt;
    ps[i].tat = ps[i].ct - ps[i].at;
    ps[i].wt = ps[i].tat - ps[i].bt;
    ps[i].rt = ps[i].wt;

    sum_tat += ps[i].tat;
    sum_wt += ps[i].wt;
    sum_rt += ps[i].rt;
    total_idle_time += (i == 0) ? 0 : (ps[i].start_time - ps[i - 1].ct);
  }

  length_cycle = ps[n - 1].ct - ps[0].start_time;
  cpu_utilization = (float)(length_cycle - total_idle_time) / length_cycle;

  // sorting by PID for better readability
  qsort((void *)ps, n, sizeof(struct process_struct), comparatorPID);

  // Output
  printf("\nPID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i, ps[i].at, ps[i].bt, ps[i].start_time, ps[i].ct, ps[i].tat, ps[i].wt, ps[i].rt);
  }

  printf("\n");

  printf("\nAverage Turn Around Time= %f", sum_tat / n);
  printf("\nAverage Waiting Time= %f", sum_wt / n);
  printf("\nAverage Response Time= %f", sum_rt / n);
  printf("\nThroughput= %f", n / (float)length_cycle);
  printf("\nCPU Utilization Percentage = %f", cpu_utilization * 100);

  printf("\n\n");

  return 0;
}