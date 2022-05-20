//Bubble Sort
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter number of elements";
    cin>>n;

    int array[n];
    for(int i=0 ;i<n ;i++)
    {
        cin>>array[i];
    }



    int count =0;
    while (count<n-1)
    {
        for(int i=0 ;i<n-count-1;i++)
        {
            if(array[i]>array[i+1])
            {
                int temp =array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
            }
        count++;
        }

    }
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<"No. of comparison  "<<count<<endl;
    return 0;
}

