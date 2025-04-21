#include <stdio.h>
#include <string.h>

#define MAX_ABONENTS 100

struct abonent
{
    char name[10];
    char second_name[10];
    char tel[10];
};

struct abonent directory[MAX_ABONENTS];
int count = 0;

void add_abonent()
{
    if (count >= MAX_ABONENTS)
    {
        printf("Spravochnik zapolnen!\n");
        return;
    }

    printf("Write name: ");
    scanf("%9s", directory[count].name);
    printf("Write second name: ");
    scanf("%9s", directory[count].second_name);
    printf("Write tel number: ");
    scanf("%9s", directory[count].tel);

    count++;
    printf("Subscriber added!\n");
}

void del()
{
    int number;
    printf("Write index: ");
    scanf("%d", &number);

    if (number < 1 || number > count)
    {
        printf("Incorrect index!\n");
        return;
    }

    number--;

    /* изначально был этот варик, потом узнал про memset
    directory[num].name[0] = '\0';
    directory[num].second_name[0] = '\0';
    directory[num].tel[0] = '\0';
    */

    memset(&directory[number], 0, sizeof(struct abonent));

    for(int i = number; i < count - 1; i++)
    {
        directory[i] = directory[i+1];
    }

    count--;
    printf("Subscriber deleted!\n");
}

void search()
{
    char search_name[10];

    printf("Write name for search: ");
    scanf("%9s", search_name);

    printf("Results:\n");

    for(int i = 0; i < count; i++)
    {
        if(strcmp(directory[i].name, search_name) == 0)
        {
            printf("%d) %s %s %s\n", 
                   i + 1, 
                   directory[i].name, 
                   directory[i].second_name, 
                   directory[i].tel);
        }
    }
}

int SeeAll()
{
    printf("All subscribers:\n");
    for(int i = 0; i < count; i++)
    {
        printf("%d) %s %s %s\n", 
               i + 1, 
               directory[i].name, 
               directory[i].second_name, 
               directory[i].tel);
    }
}

int main()
{
    int choice;
    
    do
    {
        printf("\nMenu:\n");
        printf("1) Add subscriber\n");
        printf("2) Delete subscriber\n");
        printf("3) Search subscriber by name\n");
        printf("4) Print all subscribers\n");
        printf("5) Exit\n");
        printf("Choose one option: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: add_abonent(); break;
            case 2: del(); break;
            case 3: search(); break;
            case 4: SeeAll(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Wrong choise!\n");
        }
    } while (choice != 5);

    return 0;
}

//сразу сделано 5.1