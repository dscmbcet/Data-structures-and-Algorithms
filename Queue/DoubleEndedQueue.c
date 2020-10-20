#include <stdio.h>
int MAX;
int front=-1;
int rear=-1;
int a[20];

void enque_front(){
    int ele;
    printf("Enter the element");
    scanf("%d",&ele);
    if((front==0)&&(rear==MAX-1)||(rear+1)==front){
        printf("Overflow");
    }
    else if(front==-1&&rear==-1){
        front=0;
        rear=0;
        a[front]=ele;
    }
    else{
        if(front==0){
            front=MAX-1;
            a[front]=ele;
        }
        else{
            front=front-1;
            a[front]=ele;
        }
    }
}

void enque_rear(){
    int ele;
    printf("Enter the element");
    scanf("%d",&ele);
    
    if((front==0)&&(rear==MAX-1)||(rear+1)==front){
        printf("Overflow");
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        a[front]=ele;
    }
    else{
       rear=(rear+1)%MAX;
       a[rear]=ele;
    }
}

void deque_rear(){ //rear 
    int item;
    if((front==-1)&&(rear==-1)){
        printf("Underflow");
    }
    else if(front==rear){
      item=a[rear];
      front=-1;
      rear=-1;
    }
    else{
        if(rear==0){
            item=a[rear];
            rear=MAX-1;
        }
        else{
           item=a[rear];
           rear=rear-1;
        }
    }
}
void deque_front(){ //front
    int item;
    if((front==-1)&&(rear==-1)){
        printf("Underflow \n");
    }
    else if(front==rear){
      item=a[rear];
      front=-1;
      rear=-1;
    }
    else{
        item=a[front];
        front=(front+1)%MAX;
    }
}
void displayQueue(){
    if(front==-1){
        printf("Empty queue");
        return;
    }
    printf("The queue is \n");
   if(front<=rear){
       for(int i=front;i<=rear;i++){
           printf("%d\t",a[i]);
       }
   }else{
       for(int i=front;i<MAX;i++){
           printf("%d\t",a[i]);
       }
       for(int i=0;i<=rear;i++){
           printf("%d\t",a[i]);
       }
   }
}
void main()
{
    int ch;
   
    printf("Enter size");
    scanf("%d",&MAX);

do{
        printf("1.Insertion through Front-  2.Insertion through rear- 3.Deletion through  front- 4.Deletion through rear 5.display \n");
scanf("%d",&ch);
switch(ch){
    case 1:enque_front();
    break;
    case 2:enque_rear();
    break;
    case 3:deque_front();
    break;
    case 4:deque_rear();
    break;
    case 5:displayQueue();
    break;
    default:printf("Invalid");
}
}while(ch==1||ch==2||ch==3||ch==4||ch==5);
}
