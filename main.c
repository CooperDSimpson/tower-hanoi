#include <stdio.h>

int move = 0;

void hanoi(int n, char from, char to, char aux) {
  move ++;
  if (n == 1) {
    printf("Move disk 1 from rod %c to rod %c\n", from, to);
    return;
  }
    
  hanoi(n - 1, from, aux, to);
  
  printf("Move disk %d from rod %c to rod %c\n", n, from, to);
    
  hanoi(n - 1, aux, to, from);
}

int calculate_moves(int n) {
  int moves = 1;
  for (int i = 0; i < n; i++) {
    moves *= 2;
  }
  return moves - 1;
}

void print_initial_state(int n) {
  printf("\nInitial state:\n");
  printf("Rod A: ");
  for (int i = n; i >= 1; i--) {
    printf("%d ", i);
  }
  printf("\nRod B: (empty)\n");
  printf("Rod C: (empty)\n");
  printf("\nGoal: Move all disks from Rod A to Rod C\n");
  printf("Rules: 1) Only one disk can be moved at a time\n");
  printf("       2) Only the top disk can be moved\n");
  printf("       3) A larger disk cannot be placed on a smaller disk\n\n");
}

int main() {
  int n;
    
  printf("Enter the number of disks: ");
  scanf("%d", &n);
    
  // Validate input
  if (n <= 0) {
    printf("Please enter a positive number of disks.\n");
    return 1;
  }
    
  if (n > 10) {
    printf("Warning: %d disks will require %d moves. This might take a while!\n", n, calculate_moves(n));
    printf("Press Enter to continue...");
    while (getchar() != '\n');  // Wait until Enter is pressed
    //
  }
    
  print_initial_state(n);
    
  printf("Solution (minimum %d moves):\n", calculate_moves(n));
  printf("================================\n");
    
  hanoi(n, 'A', 'C', 'B');
    
  printf("================================\n");
  printf("All disks successfully moved to Rod C in %d moves!\n", move);
    
  return 0;
}
