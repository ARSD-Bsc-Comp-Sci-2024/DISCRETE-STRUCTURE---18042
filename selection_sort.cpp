#include<iostream>
using namespace std;
void selection(int arr[], int n)
{
    int mini,temp;
    for(int i = 0; i<n; i++) {
        mini=i;
        for(int j=i+1;j<n;j++)
            if(arr[j]<arr[mini])
                mini=j;
            int temp= arr[i];
            arr[i]= arr[mini];
            arr[mini]=temp;
    }
}
void print(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int n;
    cout<<"Enter no of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Initial array is: ";
    print(arr,n);
    selection(arr,n);
    cout<<"Sorted array is: ";
    print(arr,n);
    return 0;
}
