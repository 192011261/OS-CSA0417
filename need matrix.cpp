#include<stdio.h>
#include<stdlib.h>

int main() {
    int processes = 5, resources = 3;
    int allocation[5][3] = { {1, 1, 2},
                             {2, 1, 2},
                             {3, 0, 1},
                             {0, 2, 0},
                             {1, 1, 2} };
                             
    int max[5][3] = { {5, 4, 4},
                      {4, 3, 3},
                      {9, 1, 3},
                      {8, 6, 4},
                      {2, 2, 3} };

    int available[3] = {3, 2, 1};
    int need[5][3];

    
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

   
    printf("Need matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    return 0;
}
