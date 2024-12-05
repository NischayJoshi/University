#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void best_fit(int n, int processes[], int b, int blocks[])
{
  printf("Best Fit Allocation: \n");

  bool occupied[b];
  for (int i = 0; i < b; i++)
  {
    occupied[i] = false;
  }

  for (int i = 0; i < n; i++)
  {
    int idx = -1;
    int diff = processes[i];
    for (int j = 0; j < b; j++)
    {
      if (occupied[j] != true && blocks[j] >= processes[i] && blocks[j] - processes[i] < diff)
      {
        diff = blocks[j] - processes[i];
        idx = j;
      }
    }
    if (idx == -1)
    {
      printf("Process %d of size %d is not assigned to any block\n", i, processes[i]);
    }
    else
    {
      occupied[idx] = true;
      printf("Process %d of size %d allocated to block %d of size %d\n", i, processes[i], idx, blocks[idx]);
    }
  }
}

void first_fit(int n, int processes[], int b, int blocks[])
{
  printf("First Fit Allocation: \n");

  bool occupied[b];
  for (int i = 0; i < b; i++)
  {
    occupied[i] = false;
  }

  for (int i = 0; i < n; i++)
  {
    bool flag = false;
    for (int j = 0; j < b; j++)
    {
      if (occupied[j] != true && blocks[j] >= processes[i])
      {
        occupied[j] = true;
        printf("Process %d of size %d allocated to block %d of size %d\n", i, processes[i], j, blocks[j]);
        flag = true;
        break;
      }
    }
    if (flag == false)
    {
      printf("Process %d of size %d is not assigned to any block\n", i, processes[i]);
    }
  }
}

void worst_fit(int n, int processes[], int b, int blocks);

int main()
{

  int b = 0;
  printf("Enter the number of blocks: ");
  scanf("%d", &b);

  int blocks[b];
  printf("Enter the size of each block:\n");
  for (int i = 0; i < b; i++)
  {
    scanf("%d", &blocks[i]);
  }

  int n = 0;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  int processes[n];
  printf("Enter the size of each process:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &processes[i]);
  }
  printf("\n");

  best_fit(n, processes, b, blocks);
  printf("\n\n");

  first_fit(n, processes, b, blocks);
}