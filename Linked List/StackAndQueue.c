#include <stdio.h>
#include <stdlib.h>
int item,ch;

struct node *new=NULL;
struct node *tmp=NULL;
struct node *front=NULL;
struct node *rear=NULL;
struct node *TOP=NULL;

struct node{
    int info;
    struct node *ptr;
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
void enque()
{
 int ele;
 printf("Enter the element: ");
 scanf("%d",&ele);
    new=getNode();
    new->info=ele;
    if(front==NULL&&rear==NULL){
        front=rear=new;
    }
    else{
        rear->ptr=new;
        rear=new;
    }
}
void deque(){
  if(front==NULL){
  printf("Underflow!\n");
  }
  tmp=front;
if(front==rear){
    item=tmp->info;
    front=rear=NULL;
  }
else{
    item=tmp->info;
    front=front->ptr;
 }
 free(tmp);
}
void queue_display(){
    tmp=front;
    if(tmp==NULL){
        printf("Empty");
    }
    else{
       while(tmp!=NULL)
        {
        printf("%d , ",tmp->info);
        tmp=tmp->ptr;
    }
    printf("\n");
  }
}



void pop(){
    if(TOP==NULL){
        printf("Underflow");
    }
    else{
        item=TOP->info;
        tmp=TOP;
        TOP=TOP->ptr;
        free(tmp);
        printf("Item popped: %d\n",item);
    }
}
void push(){
     int ele;
 printf("Enter the element: ");
 scanf("%d",&ele);
    new=getNode();
    new->info=ele;
      new->ptr = TOP;
  TOP=new;
    
}



void stack_display(){
    tmp=TOP;
         if(tmp==NULL){
            printf("Empty");
        }
        else{
        while(tmp!=NULL)
        {
  printf("%d , ",tmp->info);
  tmp=tmp->ptr;
        }
        printf("\n");
    }
}
void STACK() {
   do{
    printf("CHOOSE- 1:PUSH 2:POP 3:display ");
    scanf("%d",&ch);
    switch(ch){
        case 1:push();
        break;
        case 2:pop();
        break;
        case 3:
            stack_display();
            break;
        default:printf("Invalid");
    }
   }while(ch==1||ch==2||ch==3);
}
void QUEUE() {
   do{
    printf("CHOOSE- 1:Enque 2:Deque 3:display ");
    scanf("%d",&ch);
    switch(ch){
        case 1:enque();
        break;
        case 2:deque();
        break;
        case 3:
            queue_display();
            break;
        default:printf("Invalid");
    }
   }while(ch==1||ch==2||ch==3);
}
void main() {
   do{
    printf("1:STACK 2:QUEUE ");
    scanf("%d",&ch);
    switch(ch){
        case 1:STACK();
        break;
        case 2:QUEUE();
        break;

        default:printf("Invalid");
    }
   }while(ch==1||ch==2);
}
