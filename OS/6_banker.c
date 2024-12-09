#include <stdio.H>
#include <stdlib.h>
#include <stdbool.h>
#define max 50

int main()
{
  int n, m;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  printf("Enter the number of resources: ");
  scanf("%d", &m);

  int allocated[max][max];
  int maximum[max][max];
  int needed[max][max];
  int available[max];

  printf("Enter the allocation matrix:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%d", &allocated[i][j]);
    }
  }

  printf("Enter the maximum matrix:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%d", &maximum[i][j]);
    }
  }

  // Setting needed matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      needed[i][j] = maximum[i][j] - allocated[i][j];
    }
  }

  printf("Enter the available resources:\n");
  for (int i = 0; i < m; i++)
  {
    scanf("%d", &available[i]);
  }

  bool is_completed[max] = {false};
  int safe_sequence[max];

  int safe = -1;
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      if (!is_completed[i])
      {
        bool can_complete = true;
        for (int j = 0; j < m; j++)
        {
          if (needed[i][j] > available[j])
          {
            can_complete = false;
            break;
          }
        }
        if (can_complete)
        {
          safe_sequence[++safe] = i;
          is_completed[i] = true;
          for (int j = 0; j < m; j++)
          {
            available[j] += allocated[i][j];
          }
        }
      }
    }
  }

  bool is_safe = true;
  for (int i = 0; i < n; i++)
  {
    if (!is_completed)
    {
      is_safe = false;
      break;
    }
  }

  if (!is_safe)
  {
    printf("Deadlock Detected!\n");
  }
  else
  {
    printf("Safe Sequence: ");
    for (int i = 0; i < n; i++)
    {
      printf("%d ", safe_sequence[i]);
    }
  }
  return 0;
}