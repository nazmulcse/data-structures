/*
    Singly Linked List implementation
    Using C language.
    @Author Nazmul Hasan
    Contact: nazmul.sbpgc@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>
#define NULL 0

struct linked_list{
    int number;
    struct linked_list *next;
};

typedef struct linked_list node;    // Define a type node variable of struct linked_list type

void create(node *myList);
void print(node *myList);

int main()
{
    node *head; // Define a head pointer of node type
    head = (node *)malloc(sizeof(node));    // Allocate a dynamic memory of node type in head pointer
    create(head);   // Send first allocated memory address of node type in create function
    print(head);
}

void create(node *myList){
    printf("Enter a number for adding into linked list. Enter -9999 for close\n");
    scanf("%d",&myList->number);
    if(myList->number == -9999){
        myList->next = NULL;
    }else{
        myList->next = (node *)malloc(sizeof(node));    // Assign new memory of node type in next variable
        create(myList->next);   //Pass new memory in create function
    }
}
void print(node *myList){
    printf("%d ",myList->number);
    if(myList->next == NULL)
        return;
    print(myList->next);
}
