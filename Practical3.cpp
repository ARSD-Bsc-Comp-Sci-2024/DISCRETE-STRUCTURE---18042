#include "bits/stdc++.h"
using namespace std;


class Relation {
    public:

vector<vector<int> > rel;

    Relation(int n){

        cout<<"Enter Matrix Representation of Relation :"<<endl;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for(int j=0 ; j<n ; j++){
                int a;
                cin>>a;
                temp.push_back(a);

            }
            rel.push_back(temp);

        }


    }

    void display(){
        for (int i = 0; i < rel.size(); i++)
        {
            for (int j = 0; j < rel[i].size(); j++)
                cout << rel[i][j] << " ";
            cout << endl;
        }
    }

    bool isReflexive(){
        for (int i = 0; i < rel.size(); i++)
        {
            if(rel[i][i] != 1){
                return false;
            }
        }
        return true;
    }

    bool isSymmetric(){
        for (int i = 0; i < rel.size(); i++)
        {
            for (int j = 0; j < rel[i].size(); j++)
            {
                if (rel[i][j] == 1 && rel[j][i] != 1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isTransitive(){
        for (int i = 0; i < rel.size(); i++)
        {
            for (int j = 0; j < rel[i].size(); j++)
            {
                if (rel[i][j] == 1 && rel[i][j+1]==1 && rel[i+1][j+1] !=1 )
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){

    int n;
    cout<<"Enter size of matrix : ";
    cin>>n;
    Relation r1(n);

    // r1.display();

    if(r1.isReflexive()){
        cout<<"Relation is reflexive"<<endl;
    }
    else{
        cout<<"Relation is not reflexive"<<endl;
    }

    if(r1.isSymmetric()){
        cout << "Relation is Symmetric" << endl;
    }
    else{
        cout << "Relation is not Symmetric" << endl;
    }

    if(r1.isTransitive()){
        cout << "Relation is Transitive" << endl;
    }
    else{
        cout << "Relation is not Transitive" << endl;
    }

    return 0;
}
