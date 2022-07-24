#include <iostream>
#include <math.h>
using namespace std;

bool ismember(int set[] , int n, int key){
    for(int i=0 ; i<n; i++){
        if(key == i){
            return true;
        }
    }
    return false;
}

void powerSet(int set[], int n){
    int pow_size = pow(2,n);

    for(int i=0 ; i<pow_size; i++){
        for(int j=0 ; j<n; j++){
            if( i & ( 1<<j )){
                cout<<set[j];
            }
        }
        cout<<endl;
    }

}

int main(){


    int n;
    cout<<"No of elements : ";
    cin>>n;

    int set[n];

    cout<<"Enter elements : ";
    for(int i=0 ; i<n; i++){
        cin>>set[i];
    }

    cout<<ismember(set,n,5)<<endl;
    cout<<"power set of set is" ;
    powerSet(set,n);
}
