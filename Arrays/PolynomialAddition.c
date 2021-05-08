#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void read_poly(float p[],int d){
    for(int i=d;i>=0;i--){
        scanf("%f",&p[i]);
    }
}
void print_poly(float p[],int d){
    for(int i=d;i>=0;i--){
        if(p[i]!=0){
            if(i==d)
             printf("%.2fx^%d",p[i],i); //Representing the term with the highest exponent power
             else if(i==1)
             printf("+ %.2fx ",p[i]); //Representation of term with exponent's power equals 1
             else if(i==0)
             printf("+ %.2f",p[i]); //Represntation of term with exponent's power equals 0
             else
             printf("+ %.2f x^%d",p[i],i); 
        }
    }
}
int add_poly(float p1[],float p2[],float p3[],int d1,int d2){
    int d3;
    d3=d1>d2?d1:d2;
    for(int i=0;i<=d3;i++){
        p3[i]=p1[i]+p2[i];
    }
    return d3;
}


int main()
{
    float pol1[MAX+1]={0.0},pol2[MAX+1]={0.0},pol3[MAX+1]={0.0};
    int d1,d2,d3;
    printf("\n Enter the degree of the first polynomial and second polynomial");
    scanf("%d %d",&d1,&d2);
    if(d1<1||d2<1||d1>MAX||d2>MAX){
            printf("The degree is not valid");
            getch();
            exit(0);
    }
    printf("Enter the coefficients of first polynomial from x^%d to x^0",d1);
    read_poly(pol1,d1);
    printf("Enter the coefficients of second polynomial from x^%d to x^0",d1);
    read_poly(pol2,d2);
    d3=add_poly(pol1,pol2,pol3,d1,d2);
    printf("\n The first polynomial is");
    print_poly(pol1,d1);
    printf("\n The second polynomial is");
    print_poly(pol2,d2);
    printf("\n Sum of the two polynomials:");
    print_poly(pol3,d3);
    getch();
    
}
