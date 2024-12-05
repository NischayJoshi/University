#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// Structure to store process information
struct process_struct
{
  int pid;                         // Process ID
  int at;                          // Arrival Time
  int bt;                          // Burst Time
  int ct, wt, tat, rt, start_time; // Completion Time, Waiting Time, Turnaround Time, Response Time, Start Time
};

// Function to find maximum of two numbers
int findmax(int a, int b)
{
  return a > b ? a : b;
}

// Function to find minimum of two numbers
int findmin(int a, int b)
{
  return a < b ? a : b;
}

int main()
{
  int n;
  printf("Enter total number of processes: ");
  scanf("%d", &n);
  struct process_struct ps[100];                             // Array to hold process information
  bool is_completed[100] = {false}, is_first_process = true; // Flags for completion and checking first process

  // Variables to hold total waiting time, turnaround time, etc.
  int sum_tat = 0, sum_wt = 0, sum_rt = 0, total_idle_time = 0, prev = 0, length_cycle;
  float cpu_utilization;

  int max_completion_time, min_arrival_time; // For calculating CPU Utilization and throughput
  int current_time = 0;                      // Tracks current time in simulation
  int completed = 0;                         // Number of completed processes

  // Input Arrival Time and Burst Time for each process
  for (int i = 0; i < n; i++)
  {
    printf("\nEnter Process %d Arrival Time: ", i);
    scanf("%d", &ps[i].at);
    printf("Enter Process %d Burst Time: ", i);
    scanf("%d", &ps[i].bt);
    ps[i].pid = i; // Assigning process ID
    printf("\n");
  }

  // Loop until all processes are completed
  while (completed != n)
  {
    int min_index = -1;    // To store index of process with shortest burst time
    int minimum = INT_MAX; // Variable to track the minimum burst time

    // Find the process with the shortest burst time that has arrived and is not completed
    for (int i = 0; i < n; i++)
    {
      if (ps[i].at <= current_time && is_completed[i] == false)
      {
        // Compare burst times
        if (ps[i].bt < minimum)
        {
          minimum = ps[i].bt;
          min_index = i;
        }

        // In case of tie, choose the process with earlier arrival time
        if (ps[i].bt == minimum)
        {
          if (ps[i].at < ps[min_index].at)
          {
            minimum = ps[i].bt;
            min_index = i;
          }
        }
      }
    }

    // If no process has arrived, increment the current time (CPU is idle)
    if (min_index == -1)
    {
      current_time++;
    }
    else
    {
      // Set start time and completion time for the chosen process
      ps[min_index].start_time = current_time;
      ps[min_index].ct = ps[min_index].start_time + ps[min_index].bt;

      // Calculate Turnaround Time, Waiting Time, and Response Time
      ps[min_index].tat = ps[min_index].ct - ps[min_index].at;        // TAT = CT - AT
      ps[min_index].wt = ps[min_index].tat - ps[min_index].bt;        // WT = TAT - BT
      ps[min_index].rt = ps[min_index].start_time - ps[min_index].at; // RT = Start Time - Arrival Time

      // Update total TAT, WT, RT and idle time
      sum_tat += ps[min_index].tat;
      sum_wt += ps[min_index].wt;
      sum_rt += ps[min_index].rt;
      total_idle_time += (is_first_process == true) ? 0 : (ps[min_index].start_time - prev);

      // Mark process as completed and update current time
      completed++;
      is_completed[min_index] = true;
      current_time = ps[min_index].ct;
      prev = current_time;      // Store the current time as the previous for the next process
      is_first_process = false; // First process flag is set to false after first process is done
    }
  }

  // Calculate total cycle length (time span from the first process arrival to last process completion)
  max_completion_time = INT_MIN;
  min_arrival_time = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    max_completion_time = findmax(max_completion_time, ps[i].ct);
    min_arrival_time = findmin(min_arrival_time, ps[i].at);
  }
  length_cycle = max_completion_time - min_arrival_time;

  // Output the process table
  printf("\nPID\tAT\tCPU_BT\tCT\tTAT\tWT\tRT\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", ps[i].pid, ps[i].at, ps[i].bt, ps[i].ct, ps[i].tat, ps[i].wt, ps[i].rt);
  }
  printf("\n");

  // Calculate CPU Utilization and Throughput
  cpu_utilization = (float)(length_cycle - total_idle_time) / length_cycle;

  // Output Average Times, Throughput, and CPU Utilization
  printf("\nAverage Turn Around Time = %f", (float)sum_tat / n);
  printf("\nAverage Waiting Time= %f", (float)sum_wt / n);
  printf("\nAverage Response Time= %f", (float)sum_rt / n);
  printf("\nThroughput= %f", n / (float)length_cycle);
  printf("\nCPU Utilization Percentage= %f", cpu_utilization * 100);

  return 0;
}
