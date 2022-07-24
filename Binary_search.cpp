#include <iostream>
using namespace std;
int binary(int arr[],int key,int low,int high)
{
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==key)
            return mid;
        if(arr[mid]>key){
            return binary(arr,key,low,mid-1);
        }
        else
            return binary(arr,key,mid+1,high);
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter number of elements of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in ascending/descending order: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter element to be searched: ";
    cin>>key;
    int ans=binary(arr,key,0,n);
    (ans==-1) ? cout<<"Element is not present." : cout<<"Element is present at index "<<ans+1;
    return 0;
}
