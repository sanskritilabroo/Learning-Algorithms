// Write a program for computing ⌊√n ⌋ for any positive integer and analyze its time 
// efficiency. Besides assignment and comparison, your program may only use the 
// four basic arithmetic operations.
 
 #include <stdio.h>

int floorSqrt(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    int start = 0, end = n, result;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (mid * mid == n) {
            return mid;
        } else if (mid * mid < n) {
            start = mid + 1;
            result = mid; // Save the result and continue searching in the right half
        } else {
            end = mid - 1;
        }
    }

    return result;
}

int main() {
    int n;

    // Input from the user
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a positive integer.\n");
    } else {
        // Calculate and print the floor square root
        int result = floorSqrt(n);
        printf("The floor square root of %d is: %d\n", n, result);
    }

    return 0;
}
