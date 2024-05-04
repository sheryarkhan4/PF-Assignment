#include <stdio.h>
int collatzSequenceLength(long long n) {
int length = 1;
while (n != 1) {
    if (n % 2 == 0)
         n /= 2;
    else
         n = 3 * n + 1;
       length++;
    }
    return length;
}

// Function to find the starting number under N with the longest Collatz sequence
void findLongestCollatzSequence(long long N){
	long long maxStartingNumber = 1;
	int maxLength = 0;
	long long i;
for (i = 1; i < N; i++){
	int length = collatzSequenceLength(i);
        if (length > maxLength) {
           maxLength = length;
            maxStartingNumber = i;
    }
}

    printf("The starting number under %lld with the longest Collatz sequence is: %lld\n", N, maxStartingNumber);
    printf("Length of the longest Collatz sequence: %d\n", maxLength);
}

int main(void) {
long long N;
    printf("Enter the upper limit N: ");
    scanf("%lld", &N);

findLongestCollatzSequence(N);

return 0;
} 
