#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X;
    int Y;
    int mask = 0xFF00FFFF;
    scanf("%u", &X);
    scanf("%u", &Y);
    X &= mask;
    Y = Y << 16;
    X |= Y;
    printf("%u", X);
    return 0;
}