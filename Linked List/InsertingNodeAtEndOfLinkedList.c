#include<stdlib.h>
#include <stdio.h>

struct node *new=NULL;
struct node *head=NULL;
struct node *PTR=NULL;


struct node{
    int info;
    struct node *link;
};

struct node * getNode(){
     new=(struct node*)malloc(sizeof(struct node));
     if(!new){
         return NULL;
     }
     else{
         return new;
     }
}


void insert()
{
    int ele;
    printf("Enter the data: ");
    scanf("%d",&ele);
    new=getNode();
    new->info=ele;
    new->link=NULL;
    if(head==NULL){
        head=new;
    }
    else{
        PTR=head;
        while(PTR->link!=NULL){
        PTR=PTR->link;   
        }
        PTR->link=new;
    }

    
}


void display(){
    PTR=head;
    while(PTR!=NULL){
        printf("%d , ",PTR->info);
        PTR=PTR->link;
    }
    printf("\n");
}

void main(){
    int ch;
   do{
    printf("1.Insert 2.Display 3.EXIT");
    printf("\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:insert();
        break;
        case 2:display();
        break;
        case 3:exit(1);
        break;
        default:printf("invalid");
    }
   }while(ch==1||ch==2||ch==3);
}
