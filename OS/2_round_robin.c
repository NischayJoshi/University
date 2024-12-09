#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct process
{
  int id;
  int at, bt, ct, tat, wt, rt, start_time;
};

int cmpAT(const void *a, const void *b)
{
  int at1 = ((struct process *)a)->at;
  int at2 = ((struct process *)b)->at;
  return at1 - at2;
}

int main()
{
  int n, quantum;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  struct process ps[n];
  float burst_remaining[n];

  for (int i = 0; i < n; i++)
  {
    ps[i].id = i + 1;
    printf("Enter the process %d Arrival Time: ", i + 1);
    scanf("%d", &ps[i].at);
  }
  for (int i = 0; i < n; i++)
  {
    printf("Enter the process %d Burst Time: ", i + 1);
    scanf("%d", &ps[i].bt);
    burst_remaining[i] = ps[i].bt;
  }

  printf("Enter the quantum time: ");
  scanf("%d", &quantum);

  // Sorting processes by arrival time
  qsort(ps, n, sizeof(struct process), cmpAT);

  int current_time = 0, completed = 0;
  bool visited[n];
  bool is_completed[n];

  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
    is_completed[i] = false;
  }

  int queue[100], front = -1, rear = -1;
  queue[++rear] = 0;
  visited[0] = true;

  float total_tat = 0, total_wt = 0, total_rt = 0;

  while (completed != n)
  {
    int index = queue[++front];

    if (burst_remaining[index] == ps[index].bt)
    { // First response
      ps[index].start_time = current_time;
      ps[index].rt = current_time - ps[index].at;
      total_rt += ps[index].rt;
    }

    if (burst_remaining[index] > quantum)
    {
      current_time += quantum;
      burst_remaining[index] -= quantum;
    }
    else
    {
      current_time += burst_remaining[index];
      burst_remaining[index] = 0;
      is_completed[index] = true;
      completed++;

      ps[index].ct = current_time;
      ps[index].tat = ps[index].ct - ps[index].at;
      ps[index].wt = ps[index].tat - ps[index].bt;

      total_tat += ps[index].tat;
      total_wt += ps[index].wt;
    }

    // Add new arrivals to the queue
    for (int i = 0; i < n; i++)
    {
      if (ps[i].at <= current_time && !visited[i])
      {
        queue[++rear] = i;
        visited[i] = true;
      }
    }

    // Re-queue the current process if it’s not completed
    if (!is_completed[index])
    {
      queue[++rear] = index;
    }
  }

  // Printing results
  printf("\nProcess No. \tAT\tBT\tCT\tTAT\tWT\tRT\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n",
           ps[i].id, ps[i].at, ps[i].bt, ps[i].ct, ps[i].tat, ps[i].wt, ps[i].rt);
  }

  printf("\nAverage Turnaround Time = %.2f", total_tat / n);
  printf("\nAverage Waiting Time = %.2f", total_wt / n);
  printf("\nAverage Response Time = %.2f\n", total_rt / n);

  return 0;
}
