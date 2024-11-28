#include <stdio.h>

int main()
{
    int N;

    scanf("%d", &N);

    int array[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }

    for(int i = 0, j = N-1; i < j; i++, j--)
    {
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
    } 

    for (int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
