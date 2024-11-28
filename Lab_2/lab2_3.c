#include <stdio.h>

int main()
{
    int N;

    scanf("%d", &N);

    if (N <= 0)
    {
        printf("Invalid input! Please enter a positive integer.\n");
        return 1;
    }

    int array[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int X = i + j;
            if(X >= N-1)
            {
                printf("%d ", array[i][j] = 1);
            } else
            {
                printf("%d ", array[i][j] = 0);
            }
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
