/*author:SC
description: implementation basic function of linked list including 
Head insertion node, tail insertion node
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* head = NULL;    //define a empty ptr head

void insertHead(int x){
    struct node* temp=(struct node*)malloc(sizeof(struct node));   //apply for a address
    temp->val=x;
    temp->next=head;
    head = temp;
}

void insertTail(int x){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp->val = x;
    temp->next = NULL;
    
    if(head==NULL)
        head = temp;
    else{
        struct node* current = head; //define a ptr variable to traverse the list
        while(current->next!=NULL){
            current=current->next;
        }
    current ->next = temp;
    }
    
}

void insertposition(int x, int n){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->val = x;
        temp->next = NULL;
    if (n == 1){
        temp->val=x;
        temp->next=head;
        head = temp;
        return;
    }
    
    struct node* current = head;
    for(int i = 1; i<n-1; i++){
        if(current == NULL){
            printf("out of range\n");
            free(temp);
            return;
        }
        current = current ->next;
    }
    
    temp->next=current->next;
    current->next = temp;
    
}

void print(){
    struct node* temp =head;
    printf("List is:");
    while(temp!= NULL){
        printf(" %d",temp->val);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    // int x,n,i;
    // printf("How many numbers?\n");
    // scanf("%d",&n);
    // for (i=0;i<n;i++){
    //     printf("Enter the numbers\n");
    //     scanf("%d",&x);
    //     //insertHead(x);

    //     insertTail(x);
    //     print();  
    // }
        insertHead(5);
        insertHead(6);
        insertHead(8);
        insertposition(4, 1);
        insertposition(7, 5);
        print();


    
    
}