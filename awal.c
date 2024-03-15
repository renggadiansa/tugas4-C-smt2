#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAwal(struct Node** headRef, int newData) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = newData;

    newNode->next = *headRef;

    *headRef = newNode;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int awal() {
    struct Node* head = NULL;
    int newData;
    char choice;

    printf("SINGEL LINKED LIST INSERT AWAL\n");

    do {
        printf("Nilai yang akan disimpan: ");
        scanf("%d", &newData);
        insertAwal(&head, newData);

        printf("Lanjutkan memasukkan data? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nData dalam linked list: ");
    printList(head);
}