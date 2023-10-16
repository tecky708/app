#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

void selectionSort(int array[],int n){
    int newArr[n];
    
    for (int i =0; i<n;i++)
    {
        int smallest=array[i];
        for (int j=i+1;j<n;j++)
        {
            if (array[j]>smallest){
                swap(smallest,array[j]);
                array[i]=smallest;
            }
            else array[i]=smallest;


        }
        newArr[i]=smallest;
    }
    printArray(newArr,n);
}

void bubbleSort(int arr[],int n){

    for (int i=0;i<n-1;i++ )
    {
        for (int j=0;j<n-1-i;j++)
        {
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    printArray(arr,n);
}
int main(){
    int arr[10]={5,8,2,6,7,1,9,10,3,4};

    selectionSort(arr,10);
    bubbleSort(arr,10);

    return 0;
}