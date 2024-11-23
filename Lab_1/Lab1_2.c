#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X;
    int Y = 128;

    scanf("%d", &X);

    if (X >= 0)
    {
        printf("Error! You entered a positive number.\n");
        return 0;
    }

    X = -X;
    
    int binary[8] = {0}; //массив, который потом использую для инвертирования двоичного числа
    int index = 0;

    for(int i = 1; i <= 8; i++)
    {
        if(X >= Y)
        {
            binary[index++] = 1;
            X -= Y;
        } else
        {
            binary[index++] = 0;
        }
        Y /= 2;
    }

    int summary = 1;
    for(int i = 0; i < 8; i++) //инвертируем
    {
        binary[i] = 1 - binary[i];
    }
    for (int i = 7; i >= 0; i--) //добавляем единицу
    {
        int sum = binary[i] + summary;
        binary[i] = sum % 2;
        summary = sum / 2;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%d", binary[i]);
    }
    return 0;
}