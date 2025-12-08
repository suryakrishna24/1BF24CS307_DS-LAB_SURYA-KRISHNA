#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Create and return a new node
struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}


void createlist(int n)
{   int data;
    for(int i=0;i<n;i++)
    {   printf("Enter data to insert:\n");
        scanf("%d",&data);
        struct Node* newnode = createNode(data);

    if (head == NULL) {
        head = newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
    }

    else{struct Node* temp = head;
    while (temp->next!=NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
    }
    }
}
void insertatfront()
{   int d;
    printf("Enter data to be inserted \n");
    scanf("%d",&d);
    struct Node* newnode=createNode(d);
    if(head==NULL)
        head=newnode;
    else
    {
        newnode->next=head;
        head=newnode;
    }
    printf("Insertion at front completed\n");

}
void insertatend()
{    int d;
     printf("Enter data to be inserted \n");
    scanf("%d",&d);
    struct Node* newnode=createNode(d);
    struct Node* temp = head;
    while (temp->next!=NULL)
        temp = temp->next;

    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
    printf("Insertion completed\n");


}

// b) Insert a new node to the LEFT of a given value
void insertLeft(int value, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    // find the node with given value
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    struct Node* newnode = createNode(data);

    // If inserting before the head
    if (temp == head) {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return;
    }

    newnode->prev = temp->prev;
    newnode->next = temp;
    temp->prev->next = newnode;
    temp->prev = newnode;
}

// c) Delete node by value
void deleteValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    // search the value
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    // If node is head
    if (temp == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }

    // If node is last
    if (temp->next == NULL) {
        temp->prev->next = NULL;
        free(temp);
        return;
    }

    // Node is in middle
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

// d) Display list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// MAIN – Menu Driven
int main() {
    int choice, data, value;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1.Create List\n");
        printf("2. Insert to the LEFT of a value\n");
        printf("3. Delete a value\n");
        printf("4. insert value at front\n");
        printf("5. insert value at end\n");
        printf("6.display\n");
        printf("7.Exit\n");
        printf("Enter your choice:\n ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter length of list: ");
                scanf("%d", &data);
                createlist(data);
                break;

            case 2:
                printf("Enter value to insert LEFT of: ");
                scanf("%d", &value);
                printf("Enter new data: ");
                scanf("%d", &data);
                insertLeft(value, data);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;
            case 4:
                insertatfront();
                break;
            case 5:
                insertatend();
                break;


            case 6:
                display();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
