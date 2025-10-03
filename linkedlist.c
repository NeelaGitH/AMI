#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
}node_t;

void printLinkedlist(node_t* head){
    node_t* temp = head;
    while (temp != NULL){
        printf("%d - ", temp->value);
        temp = temp->next;
    }
}

node_t* create_new_node(int value){
    node_t* newNode = malloc(sizeof(node_t));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;

}

void insert_at_head(node_t** head_ptr, node_t* temp){
    temp->next = *head_ptr;
    *head_ptr = temp;
}

void remove_node(node_t** head_ptr, node_t* node_to_remove){
    if(*head_ptr == node_to_remove){
        *head_ptr = (*head_ptr)->next;
        return;
    }

    node_t* temp = *head_ptr;
    while (temp != NULL && temp->next != node_to_remove){
        temp = temp->next;
    }
    if (temp == NULL) return;
    temp->next = node_to_remove->next;
    node_to_remove->next = NULL;
}

node_t* find_node(node_t* head, int value){
    node_t* tmp = head;
    while(tmp != NULL){
        if (tmp->value == value) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void insert_after(node_t* insert_after_node, node_t* newNode){
    newNode->next = insert_after_node->next;
    insert_after_node->next = newNode;
}

int main(){
    node_t* head = NULL;
    node_t* temp;

    for (int i = 0; i < 25; i++){
        temp = create_new_node(i);
        insert_at_head(&head, temp);
    }

    temp = find_node(head, 24);
    insert_after(temp, create_new_node(75));

    remove_node(&head, temp);

    printLinkedlist(head);

    return 0;
};
