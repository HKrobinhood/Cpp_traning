/*author:SC
description: implementation basic function of linked list including 
Head insertion node, tail insertion node, insert node at a specific position,
delete the node at a specific position, print the list
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



void print(){
    struct node* temp =head;
    printf("List is:");
    while(temp!= NULL){
        printf(" %d",temp->val);
        temp=temp->next;
    }
    printf("\n");
}

void deletepositon(int n){
    struct node* current = head;

    if(n == 1){
        head = current -> next;
        free(current);
        return;
    }
    
    for(int i = 0; i<n-2; i++){
        if(current == NULL){
            printf("out of range\n");
            return;
        }
        current = current -> next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    // 保存要删除的节点
    struct node* temp = current->next;
    current->next = current->next->next;  // 更新前驱节点的 next
    free(temp);  // 释放要删除的节点


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
        //insertposition(4, 1);
        //insertposition(7, 2);

        //deletepositon(6);
        print();


    
    
}