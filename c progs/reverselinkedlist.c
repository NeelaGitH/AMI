#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
    int val;
    struct LinkedList* next;
} Node;

Node* reverseLL(Node* head){
    if (head == NULL ||  head->next == NULL) return head;

    Node* temp = head;
    Node* prev = NULL;
    Node* fwd = NULL;

    while (temp != NULL){
        fwd = temp->next;
        temp->next = prev;
        prev = temp;
        temp = fwd;
    }

    return prev;
}

Node* createnewnode(int value){
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}

void addelements(Node** head_ptr, int* arr, int size){
    if (size == 0) return;
    if (*head_ptr != NULL){
        Node* temp = *head_ptr;
        while (temp->next != NULL){
            temp = temp->next;
        }

        for (int i = 0; i < size; i++){
            temp->next = createnewnode(arr[i]);
            temp = temp->next;
        }

    }

    else{
        *head_ptr = createnewnode(arr[0]);
        Node* temp = *head_ptr;

        for (int i = 1; i < size; i++){
            temp->next = createnewnode(arr[i]);
            temp = temp->next;
        }

    }
    
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d->", temp->val);
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    Node* head = NULL;
    int arr[] = {23, 34, 56, 78, 99, 44, 48,52};
    int size = sizeof(arr)/sizeof(arr[0]);

    addelements(&head, arr, size);
    printLL(head);

    Node* reverse = reverseLL(head);
    printLL(reverse);

}