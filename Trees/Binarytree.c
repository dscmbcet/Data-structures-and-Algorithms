// Implementing Binary trees and its traversal ( 3 modes )

#include <stdio.h>

struct node *root=NULL;
struct node *Raw=NULL;

struct node{
    int info;
   struct node *left;
     struct node *right;
};

struct node *create(){
    struct node *new;
    int val;
    printf("Enter data: (-1 for no data)");
    scanf("%d",&val);
    if(val==-1){
        return NULL;
    }

       new=(struct node*)malloc(sizeof(struct node));
       new->info=val;

       printf("Enter the left child of %d:\n",val);
       new->left=create();

       printf("Enter the right child of %d:\n",val);
       new->right=create();

       return new;
}

void inorder(struct node *Raw){
    if(Raw!=NULL){
        inorder(Raw->left);
         printf("%d , ",Raw->info);
        inorder(Raw->right);
    }

}
void preorder(struct node *Raw){
    if(Raw!=NULL){
        printf("%d , ",Raw->info);
        preorder(Raw->left);
        preorder(Raw->right);
    }


}
void postorder(struct node *Raw){
    if(Raw!=NULL){
        postorder(Raw->left);
        postorder(Raw->right);
        printf("%d , ",Raw->info);
    }

}

int main()
{

   root=create();
   printf("INORDER LIST IS: ");
      inorder(root);
          printf("\n");
   printf("PREORDER LIST IS: ");
      preorder(root);
      printf("\n");
   printf("POSTORDER LIST IS: ");
         postorder(root);
             printf("\n");

}
