#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *createNode(int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAfter(node **head, node *prevNode, int data) {
    node *newNode = createNode(data);

    if (prevNode == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
}

void printListt(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int after() {
    node *head = NULL;
    int nilai;
    char lagi = 'y';

    int nilai_array[100];
    int count = 0;

    printf("SINGEL LINKED LIST INSERT AFTER\n");

    while (lagi == 'y' || lagi == 'Y') {
        printf("Nilai yang akan disimpan: ");
        scanf("%d", &nilai);

        nilai_array[count++] = nilai;

        printf("Lanjut memasukan data (y/n): ");
        scanf(" %c", &lagi);
    }

    for (int i = count - 1; i >= 0; i--) {
        insertAfter(&head, NULL, nilai_array[i]);
    }

    printf("\nData yang ada dalam SLL:\n");
    printListt(head);

    printf("\nNilai yang akan disimpan: ");
    scanf("%d", &nilai);

    int sisipkan_setelah;
    printf("Disisipkan setelah Data Berapa? ");
    scanf("%d", &sisipkan_setelah);

    node *prevNode = head;
    while (prevNode != NULL && prevNode->data != sisipkan_setelah) {
        prevNode = prevNode->next;
    }

    if (prevNode != NULL) {
        insertAfter(&head, prevNode, nilai);
    } else {
        printf("Data tidak ditemukan!\n");
    }

    printf("\nData yang ada dalam SLL setelah penyisipan:\n");
    printListt(head);

    return 0;
}