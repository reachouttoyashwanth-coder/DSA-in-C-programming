#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *last = NULL;

// Insert at Beginning
void insertBeginning()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (last == NULL)
    {
        last = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
    }

    printf("Node inserted at beginning.\n");
}

// Insert at End
void insertEnd()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (last == NULL)
    {
        last = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }

    printf("Node inserted at end.\n");
}

// Insert at Specific Position
void insertPosition()
{
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        insertBeginning();
        return;
    }

    if (last == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    temp = last->next;

    for (i = 1; i < pos - 1 && temp != last; i++)
    {
        temp = temp->next;
    }

    if (i != pos - 1)
    {
        printf("Invalid position.\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;

    if (temp == last)
    {
        last = newnode;
    }

    printf("Node inserted at position %d.\n", pos);
}

// Delete at Beginning
void deleteBeginning()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    if (last == temp)
    {
        last = NULL;
    }
    else
    {
        last->next = temp->next;
    }

    free(temp);

    printf("Node deleted from beginning.\n");
}

// Delete at End
void deleteEnd()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (last->next == last)
    {
        free(last);
        last = NULL;
    }
    else
    {
        temp = last->next;

        while (temp->next != last)
        {
            temp = temp->next;
        }

        temp->next = last->next;
        free(last);
        last = temp;
    }

    printf("Node deleted from end.\n");
}

// Delete at Specific Position
void deletePosition()
{
    struct node *temp, *del;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || last == NULL)
    {
        printf("Invalid position or empty list.\n");
        return;
    }

    if (pos == 1)
    {
        deleteBeginning();
        return;
    }

    temp = last->next;

    for (i = 1; i < pos - 1 && temp != last; i++)
    {
        temp = temp->next;
    }

    if (i != pos - 1 || temp->next == last->next)
    {
        printf("Invalid position.\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;

    if (del == last)
    {
        last = temp;
    }

    free(del);

    printf("Node deleted from position %d.\n", pos);
}

// Traverse
void traverse()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while (temp != last->next);

    printf("(Back to Head)\n");
}

// Display
void display()
{
    traverse();
}

// Main Function
int main()
{
    int choice;

    while (1)
    {
        printf("\n===== CIRCULAR LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Specific Position\n");
        printf("7. Traverse\n");
        printf("8. Display\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);

            continue;
        }

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                insertPosition();
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                deletePosition();
                break;

            case 7:
                traverse();
                break;

            case 8:
                display();
                break;

            case 0:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}