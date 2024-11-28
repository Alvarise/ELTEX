#include <stdio.h>

int main()
{
    int N;

    scanf("%d", &N);

    int matrix[N][N];

    int count = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = count;
            count++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
