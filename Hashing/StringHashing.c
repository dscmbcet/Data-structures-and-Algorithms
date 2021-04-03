/* A C program that demonstrates String Hashing using chaining
   Contains functions for insertion, search and display.
   - String size constaint - 7characters
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10

struct node{
    char key[7];
    struct node *next;
};

struct node *chain[size];

void init(){
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

int StringToInt(char key){
    int number = 0;
    number = key-97;
    return number;
}

void insert(char* smt){
    int key = StringToInt(smt[0]);
    struct node *new = (struct node*)malloc(sizeof(struct node));
    strcpy(new->key,smt);
    new->next = NULL;
    int index = key%size;
    if(chain[index]==NULL){
        chain[index] = new;
    }
    else{
        struct node *temp = chain[index];
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new;
        
    }

}

int search(char* smt){
    int key = StringToInt(smt[0]);
    int index = key%size;
    struct node *temp = chain[index];
    if(temp==NULL)
        return 0;
    while(temp){
        if (strcmp(temp->key,smt)==0)
            return 1;
        temp = temp->next;    
    }
    return 0;
}

void print(){
    int i;
    
    printf("Chain\n");
    for(i=0;i<size;i++){
        struct node *temp = chain[i];
        printf("%d\t",i);
        while(temp){
            printf("%s\t",temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main(){
    int i = 0,ch;
  printf("\t\tImplementation of Division Method and Linear probing\n");
  do{
    printf("\nOperations: 1. Insert\t2. Search\t3. Display\t4.Exit\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch){
      case 1: {
          char smt[7];
          printf("\n Enter string to be inserted: ");
          scanf("%s",smt);
          insert(&smt);
          break;
      }
      
      case 2: {
                char smt[7];
                printf("\nEnter string to be searched: ");
                scanf("%s",smt);
                int x = search(&smt);
                if(x!=0){
                    printf("\nElement found ");
                }
                else
                    printf("Element Absent");
                break;

              }
      case 3: print();
              break;
      
      case 4: printf("\nExit Operation !");
              break;
      default: printf("Enter a valid choice !");
    }
  }while(ch!=4);

}
