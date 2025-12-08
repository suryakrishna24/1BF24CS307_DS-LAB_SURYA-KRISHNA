
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head1 = NULL; // Main List
struct Node* head2 = NULL; // Second List (only for concatenation)

// ---------------- CREATE LIST -----------------
void createList() {
    int n, value;
    struct Node *newNode, *temp;

    head1 = NULL; // Reset if creating again

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head1 == NULL) {
            head1 = newNode;
        } else {
            temp = head1;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

// ---------------- DISPLAY LIST -----------------
void display() {
    struct Node* temp = head1;

    if (temp == NULL) {
        printf("List is Empty\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ---------------- SORT LIST (Ascending) -----------------
void sortList() {
    if (head1 == NULL) {
        printf("List is Empty\n");
        return;
    }

    struct Node *i, *j;
    int temp;

    for (i = head1; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("List Sorted Successfully\n");
}

// ---------------- REVERSE LIST -----------------
void reverseList() {
    if (head1 == NULL) {
        printf("List is Empty\n");
        return;
    }

    struct Node *prev = NULL, *curr = head1, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head1 = prev;
    printf("List Reversed Successfully\n");
}

// ---------------- CONCATENATION -----------------
void concatenate() {
    int n, value;
    struct Node *newNode, *temp;

    printf("Creating List 2...\n");

    head2 = NULL;

    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head2 == NULL) {
            head2 = newNode;
        } else {
            temp = head2;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Attach List 2 to List 1
    if (head1 == NULL) {
        head1 = head2;
    } else {
        temp = head1;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head2;
    }

    head2 = NULL; // not needed anymore

    printf("Concatenation Successful!\n");
}

// ---------------- MAIN MENU -----------------
int main() {
    int choice;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Sort List\n");
        printf("4. Reverse List\n");
        printf("5. Concatenate With Another List\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: display(); break;
            case 3: sortList(); break;
            case 4: reverseList(); break;
            case 5: concatenate(); break;
            case 6: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
    return 0;
}

