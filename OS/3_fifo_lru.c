#include <stdio.h>
#include <stdlib.h>
#define max 50

int fifo(int frames[], int f, int requests[], int r)
{
  int front = 0, rear = 0, page_faults = 0;
  for (int i = 0; i < r; i++)
  {
    int index = -1;
    for (int j = 0; j < rear; j++)
    {
      if (frames[j] == requests[i])
      {
        index = j;
        break;
      }
    }
    if (index == -1)
    {
      page_faults++;
      if (rear < f)
      {
        frames[rear++] = requests[i];
      }
      else
      {
        frames[front] = requests[i];
        front = (front + 1) % f;
      }
    }
    print_frame(frames, f);
  }
  return page_faults;
}

int lru(int frames[], int f, int requests[], int r)
{
  int rear = 0, page_faults = 0;
  for (int i = 0; i < requests; i++)
  {
    int index = -1;
    for (int j = 0; j < rear; j++)
    {
      if (frames[j] == requests[i])
      {
        index = requests[i];
        for (int k = j; k < rear - 1; k++)
        {
          frames[k] = frames[k + 1];
        }
        frames[rear - 1] = requests[i];
        break;
      }
    }
    if (index == -1)
    {
      page_faults++;
      if (rear < f)
      {
        frames[rear++] = requests[i];
      }
      else
      {
        for (int k = 0; k < f - 1; k++)
        {
          frames[k] = frames[k + 1];
        }
        frames[f - 1] = requests[i];
      }
    }
    print_frame(frames, f);
  }
}

void print_frame(int frames[], int f)
{
  printf("Frame contents: ");
  for (int k = 0; k < f; k++)
  {
    if (frames[k] != -1)
      printf("%d ", frames[k]);
    else
      printf("- ");
  }
  printf("\n");
}

int main()
{
  int f, r;
  printf("Enter the number of frames: ");
  scanf("%d", &f);

  int frames[max], requests[max];
  for (int i = 0; i < f; i++)
  {
    frames[i] = -1;
  }

  printf("Enter the number of requests: ");
  scanf("%d", &r);

  printf("Enter all the page requests: ");
  for (int i = 0; i < r; i++)
  {
    scanf("%d", &requests[i]);
  }

  int page_faults = fifo(frames, f, requests, r);
  // int page_faults = lru(frames,f,requests,r);
  printf("Number of page faults: %d\n", page_faults);
  printf("Hit Ratio: %f\n", (float)(r - page_faults) / r);
  printf("Fault Rato: %f\n", (float)page_faults / r);
}