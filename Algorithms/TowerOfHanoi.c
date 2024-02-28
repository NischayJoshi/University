#include <stdio.h>

// Function to transfer disks from one rod to another following Tower of Hanoi rules
// Parameters:
// - n: The number of disks to transfer
// - source: The source rod
// - auxiliary: The auxiliary rod
// - destination: The destination rod
void transfer(int n, char source, char auxiliary, char destination)
{
  // Base case: If there are no disks to transfer, return
  if (n == 0)
  {
    return;
  }
  else
  {
    // Transfer n-1 disks from the source rod to the auxiliary rod, using the destination rod as temporary storage
    transfer(n - 1, source, destination, auxiliary);

    // Move the nth disk from the source rod to the destination rod
    printf("Move disk %d from %c to %c.\n", n, source, destination);

    // Transfer the n-1 disks from the auxiliary rod to the destination rod, using the source rod as temporary storage
    transfer(n - 1, auxiliary, source, destination);
  }
}

int main()
{
  int n;
  printf("Enter the number of disks: ");
  scanf("%d", &n);

  // Initialize rod labels
  char source = 'S', auxiliary = 'A', destination = 'D';

  // Call the transfer function to solve the Tower of Hanoi problem
  transfer(n, source, auxiliary, destination);
  printf("Transfer Complete!\n\n");
  return 0;
}
