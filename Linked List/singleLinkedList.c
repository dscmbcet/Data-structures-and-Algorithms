#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//creating a structure node 
struct node{
    int key;
    struct node *addr;
};

struct node *front=NULL;
struct node *rear=NULL;

//Function to display the linked list items in order
void display(){
    struct node *temp2;
    temp2 = front;
    while(temp2!=NULL){
        printf("%d\t",temp2->key);
        temp2=temp2->addr;
    }
}

//Function to display the linked list items in reverse order
void display_r(){
    int i,j,k;
    struct node *temp,*temp2;
    i=0;
    temp2=front;
    while(temp2!=NULL){
        i++;
        temp2=temp2->addr;
    }
    j=i;
    for(k=j;k>1;k--){
        temp=front;
        i=0;
        do{
            temp=temp->addr;
            i++;
        }while(i<k-1);
        printf("%d\t", temp->key);
    }
    printf("%d",front->key);
}

//Function to insert element at beginning of linked list
void insert_at_begin(int key1){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(front==NULL){
        front=rear=temp;
        temp->key=key1;
        temp->addr=NULL;
    }
    else{
        temp->addr=front;
        temp->key=key1;
        front=temp;
    }
}

//Function to insert element at th end of linked list
void insert_at_end(int key1){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(front==NULL || rear==NULL) {
        temp->key=key1;
        temp->addr=NULL;
        front=temp;
        rear=temp;
    }
    else {
        rear->addr=temp;
        temp->key=key1;
        temp->addr=NULL;
        rear=temp;
    }
}

//Function to insert the element at some position of the linked list
void insert_at_pos(int key1,int pos){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *temp1;
    int i;
    temp->key=key1;
    temp1=front;
    if(front==NULL || rear==NULL) {
        front=temp;
        rear=temp;
    }
    else {
        for(i=0;i<pos-1;i++){
            temp1=temp1->addr;
        }
        temp->addr=temp1->addr;
        temp1->addr=temp;
    }
}

//Function to delete element at beginning of linked list
void delete_at_begin(){
    if(front==NULL && rear==NULL){
        printf("list is empty");
    }
    else if(front==rear){
        free(front);
        front=rear=NULL;
    }
    else{
        struct node*temp;
        temp=front->addr;
        front=temp;
    }
}

//Function to delete element at the end of linked list
void delete_at_end()
{
    struct node*temp;
    if(front==NULL){
        printf("list is empty");
    }
    else{
    temp=front;
    while(temp->addr!=rear){
        temp=temp->addr;
    }
    printf("deleted element is  %d",rear->key);
    temp->addr=NULL;
    rear=temp;
    }
}

//Function to delete element at some position of linked list
void delete_at_pos(int pos){
    struct node *temp,*temp1;
    int i;
    if(front==NULL){
        printf("list is empty");
    }
    else if(front==rear){
        printf("deleted element is\t%d",front->key);
        front=NULL;
        rear=NULL;
    }
    else{
    temp1=front;
    for(i=1;i<pos;i++){
        temp1=temp1->addr;
    }
    temp=temp1->addr;
    temp1->addr=temp->addr;
    temp->addr=NULL;
    free(temp);
    }
}
int main(){
    int n,n1,key1,pos,pos1,n2;
    do{
        printf("\nselect an option:1.Insert\t2.delete\t3.display\t4.display reverse\t5.exit");
        scanf("%d",&n);
        switch(n){
            case 1: printf("\nenter element");
                    scanf("%d",&key1);
                    printf("\nselect where to insert?:1.begin\t2.end\t3.pos");
                    scanf("%d",&n1);
                //Switch case to choose inserting (or) deleting (or) displaying element in linked list
                    switch(n1){
                        case 1: insert_at_begin(key1);
                                break;
                        case 2: insert_at_end(key1);
                                break;
                        case 3: printf("\nenter position to insert?:");
                                scanf("%d",&pos);
                                insert_at_pos(key1,pos);
                                break;
                    }
                    break;
            case 2: printf("\nselect option where to delete?:1.begin\t2.end\t3.pos");
                    scanf("%d",&n2);
                    switch(n2){
                        case 1: delete_at_begin();
                                break;
                        case 2: delete_at_end();
                                break;
                        case 3: printf("\nenter position where to delete");
                                scanf("%d",&pos1);
                                delete_at_pos(pos1);
                                break;
                    }
                    break;
            case 3: display();
                    break;
            case 4: display_r();
                    break;
            case 5: exit(0);
            default : printf("\nselect valid option");
        }
    }while(1);
}
