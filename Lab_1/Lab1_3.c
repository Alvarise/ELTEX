#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X;
    int Y = 128;
    int count = 0;
    scanf("%u", &X);
    for(int i = 1; i <= 8; i++)
    {
        if(X >= Y)
        {
            printf("1");
            count += 1;
            X -= Y;
        } else
        {
            printf("0");
        }
        Y /= 2;
    }
    printf("\n%d", count);
    return 0;
}