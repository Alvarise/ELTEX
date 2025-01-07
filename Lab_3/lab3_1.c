#include <stdio.h>

int main()
{
    int number;
    unsigned char new_byte;

    printf("Enter number: ");
    scanf("%d", &number);

    printf("Enter new third byte(0-255): ");
    scanf("%hhu", &new_byte);

    unsigned char *byte_ptr = (unsigned char *)&number;

    byte_ptr[2] = new_byte;

    printf("New number: %d\n", number);

    return 0;
}