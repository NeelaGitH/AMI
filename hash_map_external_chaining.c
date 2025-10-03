#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person* next;

} person;

// declaring an array of pointers to structure
/* 
- table storing structs is much more bigger in size than table storing addresses of where structs are stored
- we can make a pointer point to null to show that spot is empty in the hash table
*/

person* hash_table[TABLE_SIZE];

void init_hash_table(){
    for (int i = 0; i < TABLE_SIZE;i++){
        hash_table[i] = NULL;
    }
    // empty hash table
}

void print_table(){
    printf("Start\n");
    for (int i = 0; i < TABLE_SIZE; i++){
        if (hash_table[i] == NULL){
            printf("\t%i\t ---\n", i);
        }
        else {
            person* tmp = hash_table[i];
            printf("\t%i\t", i);
            while(tmp != NULL){
                printf("%s ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("End\n");
}

unsigned int hash(char* name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

bool hash_table_insert(person* p){
    if (p == NULL) return false;
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

person* hash_table_lookup(char* name){
    int index = hash(name);
    person* tmp = hash_table[index];
    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0){
        tmp = tmp->next;
    }
    return tmp;
}

person* hash_table_delete(char* name){
    int index = hash(name);
    person* tmp = hash_table[index];
    person* prev = NULL;
    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0){
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return NULL;
    if (prev == NULL){
        //deleting the head
        hash_table[index] = tmp->next;
        return tmp;
    }

    prev->next = tmp->next;
    return tmp;

}

int main(){

    init_hash_table();
    
    person Jacob = {.name = "Jacob", .age = 30, .next = NULL};
    person Natalie = {.name = "Natalie", .age = 20, .next = NULL};
    person John = {.name = "John", .age = 25, .next = NULL};
    person Ria = {.name = "Ria", .age = 28, .next = NULL};
    person Nitish = {.name = "Nitish", .age = 58, .next = NULL};
    person Ritika = {.name = "Ritika", .age = 56, .next = NULL};
    person Neela = {.name = "Neela", .age = 21, .next = NULL};

    hash_table_insert(&Jacob);
    hash_table_insert(&Natalie);
    hash_table_insert(&John);
    hash_table_insert(&Ria);
    hash_table_insert(&Nitish);
    hash_table_insert(&Ritika);
    hash_table_insert(&Neela);

    /*person* tmp = hash_table_lookup("Jacob");
    if (tmp == NULL){
        printf("Not found\n");
    }
    else {
        printf("Found - %s\n", tmp->name);
    }

    tmp = hash_table_lookup("George");
    if (tmp == NULL){
        printf("Not found\n");
    }
    else {
        printf("Found - %s\n", tmp->name);
    }
    */

    //person* tmp = hash_table_delete("Jacob");

    /*tmp = hash_table_lookup("Jacob");
    if (tmp == NULL){
        printf("Not found\n");
    }
    else {
        printf("Found - %s\n", tmp->name);
    }
    */
    

    print_table();

    return 0;
}