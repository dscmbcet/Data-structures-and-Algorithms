/*Implementation of hashing using division method and linear probing
  Contains funtions to :
  - Insert
  - Search 
  - Delete 
  - Display

  Executed in menu-driven format
  Bucket size constraint -> upto 17 values
*/

#include<stdio.h>
#include<stdlib.h>

#define B_size 17 // Bucket Size = 17

int hash_table[B_size] = {NULL}; // Initialising hash table with null values

void insert();
int search(int);
void display();
void delete(int);

int main(){
  int i = 0,ch;
  printf("\t\tImplementation of Division Method and Linear probing\n");
  do{
    printf("\nOperations: 1. Insert\t2. Search\t3. Display\t4. Delete\t5.Exit\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch){
      case 1: insert();
              break;
      case 2: {
                int key;
                printf("\nEnter element to be searched: ");
                scanf("%d",&key);
                int x = search(key);
                if(x!=-1){
                    printf("\nElement found at index %d",x);
                }
                else
                    printf("Element Absent");
                break;

              }
      case 3: display();
              break;
      case 4:{
            int key;
            printf("Enter element to be deleted: ");
            scanf("%d",&key);
            delete(key);
            break;
      }
      case 5: printf("\nExit Operation !");
              break;
      default: printf("Enter a valid choice !");
    }
  }while(ch!=5);

}


void insert(){
  int key, index, i,funct;
  printf("Enter value to be inserted: ");
  scanf("%d",&key);
  funct = key%B_size;
  for(i=0;i<B_size;i++){
    index = (funct+i)%B_size; // index at which the key should be in the hashtable
    //index = funct+i;
    if(hash_table[index]==NULL){
      hash_table[index] = key;
      break;
    }
  }
  if(i==B_size){
    printf("Limit reached !");
  }
}

int search(int key){
  int i;
  int funct = key%B_size;
  for(i=0;i<B_size;i++){
    int index = (funct+i)%B_size;
    //index = funct+i;
    if(hash_table[index]==key){
      return index;
      break;
    }
    else if(hash_table[index]== NULL){
        return -1;
        break;
    }
  }
  if(i==B_size){
    return -1;
  }
}

void display(){
  int i;
  printf("Elements in hashtable:\n");
  printf("Index\tValue\n");
  for(i=0;i<B_size;i++){
    printf("%d\t%d", i, hash_table[i]);
    printf("\n");
  }
}

void delete(int key){
    int index = search(key);
    if(index!=-1){
        hash_table[index] = NULL;
        printf("%d is deleted",key);
    }
    else
        printf("\nElement Absent");
    
}
