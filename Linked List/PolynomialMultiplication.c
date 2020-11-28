// Polynomial Multiplication using singly linked list
// Takes in coeffients and powers of two expressions as input, and diplays them in polynomial form and also displays the product in polynomial form

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct poly{
    int coeff,power;
    struct poly* link;  // Defining structure - polynomial expression
};
// Declaring pointers
struct poly* temp = NULL; // used for traversal during display
struct poly* PPTR = NULL; // used for expression 1 traversal
struct poly* QPTR = NULL; // used for expression 2 traversal
struct poly* RPTR = NULL; // used for product expression

int  insert_exp(struct poly ** header,int coef,int expo){ // insertion of each input expression term

    struct poly* new  = (struct poly *)malloc(sizeof(struct poly));
    new->coeff = coef;
    new->power = expo;

    if(header==NULL){
        header = new;
    }
    else{
        temp = header;
        while(temp->link!=NULL)  // insertion at end is followed to keep tab of order of input and for proper display
        {
            temp = temp->link;
        }
        temp -> link = new;
        new = temp;
    }

}

void disp_exp(struct poly* header){     // Using recursion
    temp = header->link;
    if(header->link==0)
        return;

    if(temp->power == 1)
            printf("+ %dx ",temp->coeff);
    else if(temp->power == 0)
            printf("+ %d ",temp->coeff);
    else
        printf("+ %dx^%d ",temp->coeff,temp->power);

    disp_exp(header->link);
}

void multiply(struct poly* pheader, struct poly* qheader){

    struct poly* rheader = (struct poly *)malloc(sizeof(struct poly));
    rheader->link = NULL;
    rheader->coeff = NULL;
    rheader->power = NULL;
    struct poly * RPTR1 = NULL;
    if(pheader == NULL || qheader == NULL)
        printf("Not possible");
    PPTR = pheader->link;
    while(PPTR != NULL){
        QPTR = qheader->link;
        while (QPTR != NULL){
            int c = PPTR->coeff * QPTR->coeff;     // Operation
            int e = PPTR->power + QPTR->power;
            RPTR = rheader->link;
            RPTR1 = rheader;
            while(RPTR != NULL && RPTR->power>e){   // Insertion of values into product linked list
                RPTR1 = RPTR;
                RPTR = RPTR->link;
            }
            if(RPTR != NULL && RPTR->power == e){
                RPTR->coeff = RPTR->coeff+c;
            }
            else{
                struct poly* new = (struct poly *)malloc(sizeof(struct poly));
                new->power = e;
                new->coeff = c;
                new->link = RPTR1->link;
                RPTR1->link = new;
            }
            QPTR = QPTR->link;
        }
        PPTR = PPTR->link;
    }
    disp_exp(rheader);
}
int main()
{
    struct poly* pheader = (struct poly *)malloc(sizeof(struct poly));
    struct poly* qheader = (struct poly *)malloc(sizeof(struct poly));
    pheader->link = NULL;
    pheader->coeff = NULL;
    pheader->power = NULL;
    qheader->link = NULL;
    qheader->coeff = NULL;
    qheader->power = NULL;
    printf("\t\t\t\tPOLYNOMIAL MULTIPLICATION");
    int coef,expo,p1,p2,i;
    printf("\nEnter number of terms in polynomial 1: ");
    scanf("%d",&p1);
    printf("\nEnter terms in descending order of powers!");
    for(i=1;i<=p1;i++){
        printf("\nEnter coefficient of term %d :", i);
        scanf("%d", &coef);
        printf("Enter exponent:");
        scanf("%d",&expo);
        insert_exp(pheader,coef,expo);

    }
    printf("\nExpression 1: ");
    disp_exp(pheader);

    printf("\nEnter number of terms in polynomial 2: ");
    scanf("%d",&p2);
    printf("\nEnter terms in descending order of powers!");
    for(i=1;i<=p2;i++){
        printf("\nEnter coefficient of term %d :", i);
        scanf("%d", &coef);
        printf("Enter exponent:");
        scanf("%d",&expo);
        insert_exp(qheader,coef,expo);
    }
    printf("\nExpression 2: ");
    disp_exp(qheader);
    printf("\nProduct expression: ");
    multiply(pheader,qheader);
}
