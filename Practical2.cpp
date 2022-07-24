#include "bits/stdc++.h"
using namespace std;


class SET{

    public:
    int size;
    vector<int> set;

    SET(int n) {

        size = n;

        cout<<"\nEnter the elements : ";
        for(int i=0 ; i<size ; i++){
            int t;
            cin>>t;
            set.push_back(t);
        }
    }

};

int isSubset(vector<int> A, vector<int> B)
{

    sort(A.begin(), A.end());

    for (auto element : B)
    {
        if (binary_search(A.begin(), A.end(), element) == false)
        {
            return 0;
        }
    }

    return 1;
}

vector<int> unionSet(vector<int> A, vector<int> B)
{

    sort(A.begin(), A.end()) ;

    for (auto element : B )
    {
        if(binary_search(A.begin(),A.end(),element) == false)
            A.push_back(element);
    }

    return A;
}

vector<int> intersectionSet(vector<int> A, vector<int> B)
{
    vector<int> iSet;

    sort(A.begin(), A.end());

    for(auto element : B)
    {
        if(binary_search(A.begin(),A.end(),element) == true)
            iSet.push_back(element);
    }

    return iSet;
}

vector<int> complement(vector<int> A, vector<int> B)
{
    vector <int> cset;

    sort(B.begin(), B.end());

    for (auto element : A)
    {
        if (binary_search(B.begin(), B.end(), element) == false)
            cset.push_back(element);
    }

    return cset;
}

vector<int> SetDiff(vector<int> A, vector<int> B)
{

    vector<int> iset(intersectionSet(A,B));

    vector<int> set_diff(complement(A,iset));

    return set_diff;
}

vector<int> SymmDiff(vector<int> A, vector<int> B)
{
    vector <int> uset(unionSet(A,B));
    vector <int> iset(intersectionSet(A,B));

    return SetDiff(uset,iset);
}

void cartesianP(vector<int> A , vector<int> B){

    vector<pair<int,int>> cp;

    for(auto one : A){
        for(auto two : B){
            cp.push_back(make_pair(one,two));
        }
    }

    for(auto ele : cp){
        cout<<ele.first<<",";
        cout<<ele.second<<" ; ";
    }cout<<endl;
}

void menu(SET A, SET B){

    cout << "--------------------------------------------------------------------" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Subset - Check whether one set is a subset of other or not" << endl;
    cout << "2.Union  of the two sets" << endl;
    cout << "3.Intersection of the two sets" << endl;
    cout << "4.Complement" << endl;
    cout << "5.Set difference" << endl;
    cout << "6.Symmetric Difference" << endl;
    cout << "7.Cartesian product" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Please enter your choice:";

    int t;
    cin>>t;

    vector <int> arr;

    switch (t)
    {
    case 0:
        return;

    case 1:
        if(isSubset(A.set,B.set) == 1){

            cout<<"\nB is subset of A"<<endl;
        }
        else{
            cout<<"\nB is not subset of A"<<endl;
        }

        break;

    case 2:
        arr = (unionSet(A.set,B.set));
        cout << "\nUnion Set of Set A and Set B : ";
        for (auto element : arr)
        {
            cout << element << " ";
        }
        cout << endl;
        break;

    case 3:
        arr = (intersectionSet(A.set, B.set));
        cout << "\nInersection Set of Set A and Set B : ";
        for (auto element : arr)
        {
            cout << element << " ";
        }
        cout << endl;
        break;

    case 4:
        if (isSubset(A.set, B.set) == 1)
        {
            arr = (complement(A.set, B.set));
            cout << "\nComplement Set of Set B : ";
            for (auto element : arr)
            {
                cout << element << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "\nB is not subset of A , therefore its complement cannot be determined." << endl;
        }
        break;

    case 5:
        arr = (SetDiff(A.set, B.set));
        cout << "\nSet Difference of Set B from Set A : ";
        for (auto element : arr)
        {
            cout << element << " ";
        }
        cout << endl;

        break;

    case 6:
        arr = (SymmDiff(A.set, B.set));
        cout << "\nSymmetric Diff of Set A and Set B : ";
        for (auto element : arr)
        {
            cout << element << " ";
        }
        cout << endl;

        break;

    case 7:
        cartesianP(A.set , B.set);

        break;

    default:
        cout<<"\nInvalid Input"<<endl;
        break;
    }

    return menu(A,B);
}


int main(){

    int n,m;
    cout<<"\nEnter no of elements of set A : ";
    cin>>n;
    SET A(n);

    cout<<"\nEnter no of elements of set B : ";
    cin>>m;
    SET B(m);

    menu(A,B);

    return 0;

}
