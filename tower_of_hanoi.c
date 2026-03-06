#include <stdio.h>

void hanoi(int n, char source, char aux, char dest) {
    if (n > 0) {
        hanoi(n - 1, source, dest, aux);
        printf("Move disk %d from %c to %c\n", n, source, dest);
        hanoi(n - 1, aux, source, dest);
    }
}

int main() {
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    if (disks <= 0) {
        printf("Please enter a number greater than 0.\n");
    } else {
        printf("\nSteps to solve Tower of Hanoi for %d disks:\n", disks);
        hanoi(disks, 'A', 'B', 'C');
    }
    
    return 0;
}