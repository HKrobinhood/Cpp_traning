/*author:SC
description: implementation basic function of linked list including Head insertion node*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* head = NULL;    //define a empty ptr head

void insert(int x){
    struct node* temp=(struct node*)malloc(sizeof(struct node));   //apply for a address
    temp->val=x;
    temp->next=head;
    head = temp;
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
    int x,n,i;
    printf("How many numbers?\n");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Enter the numbers\n");
        scanf("%d",&x);
        insert(x);
        print();
    }
    
}