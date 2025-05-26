#include <stdio.h>
#include "../Library/calc.h"

void print_menu()
{
    printf("\nMenu\n");
    printf("1) add\n");
    printf("2) sub\n");
    printf("3) mult\n");
    printf("4) div\n");
    printf("5) exit\n");
    printf("Your choice: ");
}

void scan(int* a, int* b)
{
    printf("Write your two numbers with a separating space:\n");
    scanf("%d %d", a, b);
}

int main()
{
    while(1)
    {
        int choice;
        int a = 0;
        int b = 0;

        print_menu();

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                scan(&a, &b);
                printf("%d + %d = %d", a, b, add(a,b));
                break;
            case 2:
                scan(&a, &b);
                printf("%d - %d = %d", a, b, sub(a,b));
                break;
            case 3:
                scan(&a, &b);
                printf("%d * %d = %d", a, b, mult(a,b));
                break;
            case 4:
                scan(&a, &b);
                printf("%d / %d = %d", a, b, div(a,b));
                break;
            case 5:
                return 0;
                break;
        }
    }
    return 0;
}