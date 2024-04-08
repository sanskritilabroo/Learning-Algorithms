#include <stdio.h>

int moveCount = 0;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        moveCount++;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);
    
    moveCount++;
    
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'B', 'C');

    printf("Total number of moves: %d\n", moveCount);

    return 0;
}
