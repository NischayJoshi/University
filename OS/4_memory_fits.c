#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define max 50

void first_fit(int blocks[], int b, int processes[], int p, int occupied[])
{
  for (int i = 0; i < p; i++)
  {
    bool flag = false;
    for (int j = 0; j < b; j++)
    {
      if (!occupied[j] && blocks[j] >= processes[i])
      {
        occupied[j] = true;
        flag = true;
        printf("Process %d of size %d allocated to Block %d of size %d\n", i, processes[i], j, blocks[j]);
        break;
      }
    }
    if (!flag)
    {
      printf("Process %d of size %d could could not be allocated to any block\n", i, processes[i]);
    }
  }
}

void best_fit(int blocks[], int b, int processes[], int p, int occupied[])
{
  for (int i = 0; i < p; i++)
  {
    int index = -1, min_block = INT_MAX;
    for (int j = 0; j < b; j++)
    {
      if (!occupied[j] && blocks[j] >= processes[i] && blocks[j] < min_block)
      {
        index = j;
        min_block = blocks[j];
      }
    }
    if (index != -1)
    {
      occupied[index] = true;
      printf("Process %d of size %d allocated to Block %d of size %d\n", i, processes[i], index, blocks[index]);
    }
    else
    {
      printf("Process %d of size %d could could not be allocated to any block\n", i, processes[i]);
    }
  }
}

void worst_fit(int blocks[], int b, int processes[], int p, int occupied[])
{
  for (int i = 0; i < p; i++)
  {
    int index = -1, max_block = INT_MIN;
    for (int j = 0; j < b; j++)
    {
      if (!occupied[j] && blocks[j] >= processes[i] && blocks[j] > max_block)
      {
        index = j;
        max_block = blocks[j];
      }
    }
    if (index != -1)
    {
      occupied[index] = true;
      printf("Process %d of size %d allocated to Block %d of size %d\n", i, processes[i], index, blocks[index]);
    }
    else
    {
      printf("Process %d of size %d could could not be allocated to any block\n", i, processes[i]);
    }
  }
}

int main()
{
  int b, p;
  int blocks[max], processes[max];

  printf("Enter the number of blocks: ");
  scanf("%d", &b);
  printf("Enter the size of each block: ");
  for (int i = 0; i < b; i++)
  {
    scanf("%d", &blocks[i]);
  }

  printf("Enter the number of processes: ");
  scanf("%d", &p);
  printf("Enter the size of each process: ");
  for (int i = 0; i < p; i++)
  {
    scanf("%d", &processes[i]);
  }

  bool occupied[max];
  for (int i = 0; i < b; i++)
  {
    occupied[i] = false;
  }

  int algo;
  printf("Enter the number based on the algorithm to use:\n1: First Fit\n2: Best Fit\n3: Worst Fit\n-> ");
  scanf("%d", &algo);

  switch (algo)
  {
  case 1:
  {
    first_fit(blocks, b, processes, p, occupied);
    break;
  }
  case 2:
  {
    best_fit(blocks, b, processes, p, occupied);
    break;
  }
  case 3:
  {
    worst_fit(blocks, b, processes, p, occupied);
    break;
  }
  default:
  {
    printf("Invalid input.\n");
  }
  }
  return 0;
}