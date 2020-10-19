//Java program to implement bubble sort
import java.util.Scanner;

class BubSort
{
    //function to sort
    void sorting(int arr[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n-i-1; j++)
            {
                if(arr[j]>arr[j+1])
                {
                    //swapping
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }

    }

    //function to print array
    static void printArr(int arr[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    //main function    
    public static void main(String args[])
    {
        Scanner sc =  new Scanner(System.in);
        int n;
        System.out.print("Enter the no. of elements in the array : ");
        n = sc.nextInt();
        int arr[] = new int[n];
        System.out.print("Enter the array elements : ");
        for(int i = 0; i < n; i++)
        {
            arr[i] = sc.nextInt();
        }
        BubSort obj = new BubSort();
        obj.sorting(arr, n);
        printArr(arr, n);
        sc.close();
    }
}
