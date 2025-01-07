#include <stdio.h>
#include <string.h>

char *find_substring(const char *first, const char *second)
{
    size_t len_first = strlen(first);
    size_t len_second = strlen(second);

    if (len_second == 0)
        return (char *)first; // Empty substring is found at the beginning

    for (size_t i = 0; i <= len_first - len_second; i++)
    {
        if (strncmp(first + i, second, len_second) == 0)
            return (char *)(first + i);
    }
    return NULL;
}

int main()
{
    char first[100], second[100];

    printf("Enter the main string: ");
    fgets(first, sizeof(first), stdin);
    first[strcspn(first, "\n")] = '\0'; // Remove newline character

    printf("Enter the substring to find: ");
    fgets(second, sizeof(second), stdin);
    second[strcspn(second, "\n")] = '\0'; // Remove newline character

    char *result = find_substring(first, second);

    if (result == NULL)
    {
        printf("Substring not found.\n");
    }
    else
    {
        printf("Substring found at position: %ld\n", result - first);
    }

    return 0;
}