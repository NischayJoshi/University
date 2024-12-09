#include <stdio.h>
#include <stdlib.h>
#define max 50

int cmp(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

void scan(int tracks[], int n, int size, int head)
{

  int total_seek_movement = 0;
  int left = 0;
  int sorted_tracks[n + 2];

  for (int i = 0; i < n; i++)
  {
    sorted_tracks[i] = tracks[i];
  }
  sorted_tracks[n] = head;
  sorted_tracks[n + 1] = size - 1;

  qsort(sorted_tracks, n + 2, sizeof(int), cmp);

  while (left < n + 2 && sorted_tracks[left] < head)
  {
    left++;
  }

  for (int i = left + 1; i < n + 2; i++)
  {
    total_seek_movement += abs(head - sorted_tracks[i]);
    head = sorted_tracks[i];
  }

  for (int i = left - 1; i >= 0; i--)
  {
    total_seek_movement += abs(head - sorted_tracks[i]);
    head = sorted_tracks[i];
  }

  printf("Total Seek Movement via SCAN algorithm: %d\n", total_seek_movement);
}

void cscan(int tracks[], int n, int size, int head)
{
  int total_seek_movement = 0;
  int left = 0;
  int sorted_tracks[n + 2];

  for (int i = 0; i < n; i++)
  {
    sorted_tracks[i] = tracks[i];
  }
  sorted_tracks[n] = head;
  sorted_tracks[n + 1] = size - 1;

  qsort(sorted_tracks, n + 2, sizeof(int), cmp);

  while (left < n + 2 && sorted_tracks[left] < head)
  {
    left++;
  }

  for (int i = left + 1; i < n + 2; i++)
  {
    total_seek_movement += abs(head - sorted_tracks[i]);
    head = sorted_tracks[i];
  }

  head = 0;
  total_seek_movement += size - 1;

  for (int i = 0; i < left; i++)
  {
    total_seek_movement += abs(head - sorted_tracks[i]);
    head = sorted_tracks[i];
  }

  printf("Total Seek Movement via CSCAN algorithm: %d\n", total_seek_movement);
}

int main()
{
  int n, size, head;
  printf("Enter the number of tracks: ");
  scanf("%d", &size);

  printf("Enter the number of disk requests: ");
  scanf("%d", &n);

  int tracks[max];
  printf("Enter all the disk requests: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &tracks[i]);
  }

  printf("Enter the pointer position: ");
  scanf("%d", &head);

  scan(tracks, n, size, head);
  cscan(tracks, n, size, head);

  return 0;
}