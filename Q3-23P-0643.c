#include <stdio.h>

int evaluateHand(int hand[]);
int compareHands(int hand1[], int hand2[]);

int main() {
    int hand1[5];
    int hand2[5];

    printf("Enter hands of first Player: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &hand1[i]);
    }
 
    printf("Enter hands of Second Player: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &hand2[i]);
    }
    
    int result1 = evaluateHand(hand1);
    int result2 = evaluateHand(hand2);

    if (result1 > result2) {
        printf("Hand 1 wins!\n");
    } else if (result1 < result2) {
        printf("Hand 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}

// Function to evaluate the rank of a hand
int evaluateHand(int hand1[]) {
     int ranks[14] = {0}; // Count occurrences of each rank
    int suits[4] = {0}; // Count occurrences of each suit

    // Count occurrences of each rank and suit
    for (int i = 0; i < 5; i++) {
        ranks[hand1[i] / 10]++;
        suits[hand1[i] % 10 - 1]++;
    }

    // Check for special hands
    if (suits[0] == 5 || suits[1] == 5 || suits[2] == 5 || suits[3] == 5) {
        // Flush
        if (ranks[10] && ranks[11] && ranks[12] && ranks[13] && ranks[14]) {
            // Royal Flush
            return 10;
        } else {
            // Flush
            return 6;
        }
    }
    // Check for pairs, triples, and quadruples
    int pairs = 0;
    int triple = 0;
    int quadruple = 0;
    for (int i = 2; i < 14; i++) {
        if (ranks[i] == 2) {
            pairs++;
        } else if (ranks[i] == 3) {
            triple = 1;
        } else if (ranks[i] == 4) {
            quadruple = 1;
        }
    }
 // Check for straight
    int straight = 0;
    for (int i = 2; i < 11; i++) {
        if (ranks[i] && ranks[i + 1] && ranks[i + 2] && ranks[i + 3] && ranks[i + 4]) {
            straight = 1;
            break;
        }
    }

    // Evaluate hand rank
    if (quadruple) {
        return 8;
    } else if (triple && pairs) {
        return 7;
    } else if (straight) {
        return 5;
    } else if (pairs == 2) {
        return 4;
    } else if (triple) {
        return 3;
    } else if (pairs) {
        return 2;
    } else {
        return 1;
    }
}


// Function to compare two hands
int compareHands(int hand1[], int hand2[]) {
    // Implementation of compareHands function  
	int rank1 = evaluateHand(hand1);
    int rank2 = evaluateHand(hand2);

    if (rank1 > rank2) {
        return 1;
    } else if (rank1 < rank2) {
        return 2;
    } else {
        // Compare cards if hands have the same rank
        for (int i = 0; i < 5; i++) {
            if (hand1[i] / 10 > hand2[i] / 10) {
                return 1;
            } else if (hand1[i] / 10 < hand2[i] / 10) {
                return 2;
            }
        }
        return 0; // It's a tie
    }
}  


