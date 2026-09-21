#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int roll;
    struct Node *next;
};
struct Node *head = NULL;
// Create a new node
struct Node* createNode(int roll) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = NULL;
    return newNode;
}
// Display the list
void display() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Student Roll Numbers: ");
    while (temp != NULL) {
        printf("%d -> ", temp->roll);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Insert at beginning
void insertBeginning(int roll) {
    struct Node *newNode = createNode(roll);
    newNode->next = head;
    head = newNode;
    printf("Roll number %d inserted at beginning.\n", roll);
    display();
}
// Insert at end
void insertEnd(int roll) {
    struct Node *newNode = createNode(roll);
    struct Node *temp;
    if (head == NULL) {
        head = newNode;
    }
    else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Roll number %d inserted at end.\n", roll);
    display();
}
void search(int roll) {
    struct Node *temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Roll number %d found at position %d.\n",
                   roll, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Roll number %d is not available in the list.\n", roll);
}
void deleteRoll(int roll) {
    struct Node *temp = head;
    struct Node *prev = NULL;
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (head->roll == roll) {
        head = head->next;
        free(temp);
        printf("Roll number %d deleted successfully.\n", roll);
        display();
        return;
    }
    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Roll number %d is not available. Cannot delete.\n",
               roll);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Roll number %d deleted successfully.\n", roll);
    display();
}
int main() {
    int n, i, roll;
    int choice;
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter %d roll numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &roll);
        insertEnd(roll);
    }
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Search Roll Number\n");
        printf("4. Delete Roll Number\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertBeginning(roll);
                break;
            case 2:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertEnd(roll);
                break;

            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                search(roll);
                break;

            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteRoll(roll);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
