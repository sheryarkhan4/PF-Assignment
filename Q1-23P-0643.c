#include <stdio.h>

#define ROWS 20
#define COLS 20
#define ADJACENT_COUNT 4

#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL_TOP_LEFT 2
#define DIAGONAL_TOP_RIGHT 3

typedef struct {
    int product;
    int direction;
} MaxProductResult;

int grid[ROWS][COLS] ={
{8,02,22,97,38,15,00,40,00,75,04,05,07,78,52,12,50,77,91,8}, 
{49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,04,56,62,00},
{81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,03,49,13,36,65},
{52,70,95,23,04,60,11,42,69,24,68,56,01,32,56,71,37,02,36,91},
{22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80},
{24,47,32,60,99,03,45,02,44,75,33,53,78,36,84,20,35,17,12,50},
{32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70},
{67,26,20,68,02,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21},
{24,55,58,05,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72},
{21,36,23,9,75,00,76,44,20,45,35,14,00,61,33,97,34,31,33,95},
{78,17,53,28,22,75,31,67,15,94,03,80,04,62,16,14,9,53,56,92},
{16,39,05,42,96,35,31,47,55,58,88,24,00,17,54,24,36,29,85,57}, 
{86,56,00,48,35,71,89,07,05,44,44,37,44,60,21,58,51,54,17,58}, 
{19,80,81,68,05,94,47,69,28,73,92,13,86,52,17,77,04,89,55,40}, 
{04,52,8,83,97,35,99,16,07,97,57,32,16,26,26,79,33,27,98,66},
{88,36,68,87,57,62,20,72,03,46,33,67,46,55,12,32,63,93,53,69},
{24,94,72,18,8,46,29,32,40,62,76,36,34,62,99,69,82,67,59,85},
{74,04,36,16,74,31,49,71,48,86,81,16,23,57,05,54,16,92,33,48}, 
{61,43,52,01,89,19,67,48,04,42,16,73,38,25,39,11,20,69,36,41}, 
{72,30,23,88,20,73,35,29,78,31,90,01,01,70,54,71,83,51,54,69} 
};

int calculateProduct(int row, int col, int direction) {
    int product = 1;
    int i;
    for (i = 0; i < ADJACENT_COUNT; i++) {
        switch (direction) {
            case HORIZONTAL:
                product *= grid[row][col + i];
                break;
            case VERTICAL:
                product *= grid[row + i][col];
                break;
            case DIAGONAL_TOP_LEFT:
                product *= grid[row + i][col + i];
                break;
            case DIAGONAL_TOP_RIGHT:
                product *= grid[row + i][col - i];
                break;
        }
    }
    return product;
}

MaxProductResult maxProduct() {
    MaxProductResult result = {0, -1};
    int row,col;
    for ( row = 0; row < ROWS; row++) {
        for ( col = 0; col < COLS; col++) {
            int product = calculateProduct(row, col, HORIZONTAL);
            if (product > result.product) {
                result.product = product;
                result.direction = HORIZONTAL;
            }
            if (row < ROWS - ADJACENT_COUNT) {
                product = calculateProduct(row, col, VERTICAL);
                if (product > result.product) {
                    result.product = product;
                    result.direction = VERTICAL;
                }
            }
            if (row < ROWS - ADJACENT_COUNT && col < COLS - ADJACENT_COUNT) {
                product = calculateProduct(row, col, DIAGONAL_TOP_LEFT);
                if (product > result.product) {
                    result.product = product;
                    result.direction = DIAGONAL_TOP_LEFT;
                }
            }
            if (row < ROWS - ADJACENT_COUNT && col >= ADJACENT_COUNT - 1) {
                product = calculateProduct(row, col, DIAGONAL_TOP_RIGHT);
                if (product > result.product) {
                    result.product = product;
                    result.direction = DIAGONAL_TOP_RIGHT;
                }
            }
        }
    }
    return result;
}

const char* directionToString(int direction) {
    switch (direction) {
        case HORIZONTAL:
            return "Horizontal";
        case VERTICAL:
            return "Vertical";
        case DIAGONAL_TOP_LEFT:
            return "Diagonal (top-left to bottom-right)";
        case DIAGONAL_TOP_RIGHT:
            return "Diagonal (top-right to bottom-left)";
        default:
            return "Unknown";
    }
}

int main(void) {
    MaxProductResult result = maxProduct();
    printf("Maximum product of adjacent 4 numbers: %d\n", result.product);
    printf("Direction: %s\n", directionToString(result.direction));
    return 0;
}
