#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*) (0xFFFFFFFFFFFFFFFFUL)

typedef struct {
    char name[MAX_NAME];
    int age;

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
            printf("\t%i\t---\n", i);
        }
        else if (hash_table[i] == DELETED_NODE){
            printf("\t%i\t---<deleted node>\n", i);
        }
        else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
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
    for (int i = 0; i < TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE){
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

/*
The lookup function takes constant time. We are not running a loop to find the name. Neither did we loop thru
to find an empty spot to enter our data. The hash function is doing it for us.
The operations in hash table are linear operations. T.C = 0(1)
*/
person* hash_table_lookup(char* name){
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL) return false;

        if (hash_table[try] == DELETED_NODE) continue;

        if (strncmp(hash_table[index]->name, name, MAX_NAME) == 0){
            return hash_table[try];
        }
    }
    return NULL;
}

person* hash_table_delete(char* name){
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL) return NULL;

        if (hash_table[try] == DELETED_NODE) continue;
        
        if (strncmp(hash_table[index]->name, name, MAX_NAME) == 0){
            person* tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
    
}

int main(){

    init_hash_table();
    
    person Jacob = {.name = "Jacob", .age = 30};
    person Natalie = {.name = "Natalie", .age = 20};
    person John = {.name = "John", .age = 25};
    person Ria = {.name = "Ria", .age = 28};
    person Nitish = {.name = "Nitish", .age = 58};
    person Ritika = {.name = "Ritika", .age = 56};
    person Neela = {.name = "Neela", .age = 21};

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

    person* tmp = hash_table_delete("Jacob");

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