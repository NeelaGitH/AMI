#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student{
    char* name;
    int age;
    int rollno;
} Student;


int main(){
    Student s1;
    s1.name = malloc(50);
    strcpy(s1.name, "Radhika");
    s1.age = 15;
    s1.rollno = 56;

    Student s2;
    s2.name = malloc(50);
    strcpy(s2.name, "Ramesh");
    s2.age = 67;
    s2.rollno = 12;
    
    printf("Details of student 1 is name - %s, age - %d, rollno is %d\n", s1.name, s1.age, s1.rollno);
    printf("Details of student 2 is name - %s, age - %d, rollno is %d\n", s2.name, s2.age, s2.rollno);


}