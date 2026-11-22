#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at beginning
void insert_begin()
{
    struct node *newnode;

    newnode = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

// Insert at end
void insert_end()
{
    struct node *newnode, *temp;

    newnode = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
}

// Insert at specific position
void insert_pos()
{
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        insert_begin();
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    newnode = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;
}

// Delete at beginning
void delete_begin()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);
}

// Delete at end
void delete_end()
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// Delete at specific position
void delete_pos()
{
    struct node *temp, *del;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || head == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    temp = head;

    if (pos == 1)
    {
        head = head->next;
        free(temp);
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;

    free(del);
}

// Reverse linked list
void reverse()
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    printf("List reversed successfully\n");
}

// Count nodes
void count()
{
    struct node *temp = head;
    int c = 0;

    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }

    printf("Number of nodes = %d\n", c);
}

// Concatenate two linked lists
void concatenate()
{
    struct node *head2 = NULL;
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid number\n");
        return;
    }

    for (i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head2 == NULL)
            head2 = newnode;
        else
        {
            temp = head2;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }

    if (head == NULL)
        head = head2;
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = head2;
    }

    printf("Concatenation successful\n");
}

// Display linked list
void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int ch;

    while (1)
    {
        printf("\n--- SINGLY LINKED LIST ---\n");

        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Reverse List\n");
        printf("8. Count Nodes\n");
        printf("9. Concatenate Lists\n");
        printf("10. Display List\n");
        printf("11. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                insert_begin();
                break;

            case 2:
                insert_end();
                break;

            case 3:
                insert_pos();
                break;

            case 4:
                delete_begin();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                delete_pos();
                break;

            case 7:
                reverse();
                break;

            case 8:
                count();
                break;

            case 9:
                concatenate();
                break;

            case 10:
                display();
                break;

            case 11:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}