  
#include<stdio.h>
void Linear(int a[],int size,int ele){
    int flag=0,pos;
    for(int i=0;i<size;i++){
        if(a[i]==ele){
            flag=1;
            pos=i;
            break;
        }
    }
    if(flag==1){
        printf("element is found in the array at position: %d",pos);
    }
    else{
        printf("element not found");
    }
}

void Binary(int a[],int size,int ele){
    int temp,flag=0;
     int low=0,mid,high=size-1;
    //bubble short
    for(int i=0;i<size-1;i++)
    {
    for(int j=i+1;j<size;j++){
       
            if(a[i]>a[j]){
              temp=a[i];
              a[i]=a[j];
              a[j]=temp;
         
        }
    }
    }
    printf("The sorted array size is: ");
       for(int i=0;i<size;i++){
           printf("%d ",a[i]);
       
    }

     while(low<=high)
    {
        mid=(low+high)/2;
 
        if(ele==a[mid]){
            flag=1;
            break;
        }
        else
            if(ele>a[mid])
                low=mid+1;
            else
                high=mid-1;
    }
 
    if(flag==1)
        printf("\nElement found at position %d ",mid);
    else
        printf("\nElement not found");

}
   
   

void main()
{ 
    int ch,size,ele,a[50],flag;
    printf("Enter the array size: ");
    scanf("%d",&size);
    printf("Enter the array elements: ");
    for(int i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d",&ele);
        printf("Enter 1.Linear Search 2.Binary search : ");
    scanf("%d",&ch);

    
    switch(ch){
        case 1:
        Linear(a,size,ele);
        break;
        case 2:
        Binary(a,size,ele);
        break;
        default: 
        printf("Invalid response");
    }
}
