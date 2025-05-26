#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[10];
    char second_name[10];
    char tel[10];
} Subscriber;

typedef struct Node
{
    Subscriber data;
    struct Node* prev;  // 4/8 байт (32/64-bit)
    struct Node* next;  // 4/8 байт (32/64-bit)
} Node;

typedef struct
{
    Node* head;
    Node* tail;
} DoubleLinkedList;

void InitList(DoubleLinkedList* List)
{
    List->head = NULL;
    List->tail = NULL;
}

Node* createNode(const char* name, const char* second_name, const char* tel)
{
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory failed lol\n");
        exit(1);
    }
    strncpy(newNode->data.name, name, sizeof(newNode->data.name) - 1);
    strncpy(newNode->data.second_name, second_name, sizeof(newNode->data.second_name) - 1);
    strncpy(newNode->data.tel, tel, sizeof(newNode->data.tel) - 1);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void add(DoubleLinkedList* List)
{
    char name[10];
    char second_name[10];
    char tel[10];
    printf("\nNew abonent:\n");
    printf("Name: ");
    scanf("%9s", name);
    printf("Surname: ");
    scanf("%9s", second_name);
    printf("Phone number: ");
    scanf("%9s", tel);
    Node* newNode = createNode(name, second_name, tel);
    if(List-> tail == NULL)
    {
        List->head = List->tail = newNode;
    }
    else
    {
        newNode->prev = List->tail;
        List->tail->next = newNode;
        List->tail = newNode;
    }
    printf("New abonent added succsessfully!\n");
}

Node* find(DoubleLinkedList* List)
{
    char second_name[10];
    printf("Enter surname: \n");
    scanf("%9s", second_name);
    Node* current = List->head;
    while(current != NULL)
    {
        if(strcmp(current->data.second_name, second_name) == 0)
        {
            return current;
        }
        current = current->next;
    }
    if(current == NULL)
    {
        printf("there is no Subscriber with that second name\n");
        exit(1);
    }
}

void Delete(DoubleLinkedList* List)
{
    char tel[10];
    printf("Print phone number: \n");
    scanf("%9s", tel);
    Node* current = List->head;
    while(current != NULL)
    {
        if(strcmp(current->data.tel, tel) == 0)
        {
            if(current->prev)
            {
                current->prev->next = current->next;
            }
            else
            {
                List->head = current->next;
            }
            if(current->next)
            {
                current->next->prev = current->prev;
            }
            else
            {
                List->tail = current->prev;
            }

            free(current);
            printf("Abonent deleted\n");
            return;
        }
        current = current->next;
    }
    printf("We can't find him!\n");
}

void cleaning(DoubleLinkedList* List)
{
    Node* current = List->head;
    while(current != NULL)
    {
        Node* next = current->next;
        free(current);
        current->next;
    }
    List->head = NULL;
    List->tail = NULL;
}

int main()
{
    DoubleLinkedList List;
    InitList(&List);
    int choice;
    do
    {
        printf("1. Add Abonent\n");
        printf("2. Find Abonent by surname\n");
        printf("3. Delete abonent\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch(choice)
            {
            case 1:
                add(&List);
                break;
            case 2: {
                Node* found = find(&List);
                if(found)
                {
                    printf("\nHere is your abonent: %s %s, phone: %s\n",
                    found->data.name, found->data.second_name, found->data.tel);
                }
                else
                {
                    printf("But no one came...\n");
                }
                break;
            }
            case 3:
                Delete(&List);
                break;
            case 4:
                cleaning(&List);
                printf("Exit...\n");
                break;
            default:
                printf("Incorrect choice!\n");
        }
    } while(choice != 4);
    return 0;
}