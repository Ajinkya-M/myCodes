#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
typedef struct Node{
    int data;
    struct Node *next;
}node;

node* getnode(int x){
    node *p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}

void push_f(node **head,int x){
    node *p= *head;
    if(*head == NULL){
        *head = getnode(x);
    }else{
         p = getnode(x);
         p->next = *head;
         *head = p;
    }
}

void print(node* head){
    for(;head!=NULL;head=head->next){
        cout<<head->data<<" ";
    }
}


int main()
{
    node *head = NULL;
    push_f(&head,23);
    push_f(&head,22);
    push_f(&head,21);
    push_f(&head,20);
    push_f(&head,19);
    push_f(&head,18);
    print(head);
	return 0;
}
