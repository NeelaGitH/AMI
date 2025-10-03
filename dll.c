#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
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
    newNode->prev = NULL;
    return newNode;
}

void insert_at_head(node_t** head_ptr, node_t* newNode){
    newNode->next = *head_ptr;
    if (*head_ptr !=  NULL){
        (*head_ptr)->prev = newNode;
    }

    *head_ptr = newNode;
}

void remove_node(node_t** head_ptr, node_t* node_to_remove){
    if(*head_ptr == node_to_remove){
        *head_ptr = (*head_ptr)->next;
        if (*head_ptr != NULL){
            (*head_ptr)->prev = NULL;
        }

        free(node_to_remove);
        return;
    }

    node_t* temp = node_to_remove->prev;
    temp->next = node_to_remove->next;
    if (node_to_remove->next != NULL){
        node_to_remove->next->prev = temp;
    }

    free(node_to_remove);
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
    newNode->prev = insert_after_node;

    if (newNode->next != NULL){
        newNode->next->prev = newNode;
    }

    insert_after_node->next = newNode;
}

int main(){
    node_t* head = NULL;
    node_t* temp;

    for (int i = 0; i < 25; i++){
        temp = create_new_node(i);
        insert_at_head(&head, temp);
    }

    temp = find_node(head, 13);
    insert_after(temp, create_new_node(75));

    remove_node(&head, temp);
    remove_node(&head, head);

    printLinkedlist(head);

    return 0;
};





