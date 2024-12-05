#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct PageTable
{
  int frame_no;
  bool valid;
};

bool isPagePresent(struct PageTable PT[], int page)
{
  if (PT[page].valid == 1)
  {
    return true;
  }
  return false;
}

void updatePageTable(struct PageTable PT[], int page, int fr_no, int status)
{
  PT[page].valid = status;
  if (status == 1)
  {
    PT[page].frame_no = fr_no;
  }
}

void printFrameContents(int frame[], int no_of_frames)
{
  for (int i = 0; i < no_of_frames; i++)
  {
    print("%d ", frame[i]);
  }
  printf("\n");
}

int main()
{
  int n, no_of_frames, page_fault = 0, current = 0;
  bool flag = false;

  printf("\nEnter the number of pages: ");
  scanf("%d", &n);

  int reference_string[n];
  printf("\nEnter the page numbers:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &reference_string[i]);
  }

  printf("\nEnter the number of frames available: ");
  scanf("%d", &no_of_frames);

  int frame[no_of_frames];
  memset(frame, -1, no_of_frames * sizeof(int));

  struct PageTable PT[50];
  for (int i = 0; i < 50; i++)
  {
    PT[i].valid = 0;
  }

  printf("\n***The Contents inside the Frame array at each step***\n");
  for (int i = 0; i < n; i++)
  {

    // Step 1: Check if the page is present in the page table.
    if (!isPagePresent(PT, reference_string[i]))
    {               // Page fault occurs if page not present
      page_fault++; // Increment page fault count

      // Step 2: Add the page if frames are available and haven't been filled yet
      if (flag == false && current < no_of_frames)
      {
        frame[current] = reference_string[i];                 // Place the page in the current frame
        printFrameContents(frame, no_of_frames);              // Print the frame contents
        updatePageTable(PT, reference_string[i], current, 1); // Update the page table entry for the added page
        current++;                                            // Move to the next frame

        // If all frames are filled, wrap around and enable replacement
        if (current == no_of_frames)
        {
          current = 0;
          flag = true;
        }
      }

      // Step 3: If frames are all filled, replace pages using FIFO
      else
      {
        updatePageTable(PT, frame[current], -1, 0);           // Mark the outgoing page as invalid
        frame[current] = reference_string[i];                 // Replace with the new page
        printFrameContents(frame, no_of_frames);              // Print the new frame contents
        updatePageTable(PT, reference_string[i], current, 1); // Update the page table entry for the new page
        current = (current + 1) % no_of_frames;               // Move to the next frame in circular manner
      }
    }
  }

  printf("\nTotal number of Page Faults = %d\n", page_fault);
  printf("\nPage Fault ratio= %.2f\n", (float)page_fault / n);
  printf("\nPage Hit Ratio = %.2f\n", (float)(n - page_fault) / n);

  return 0;
}