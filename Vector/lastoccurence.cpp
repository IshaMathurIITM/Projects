#include<iostream>
#include<vector>
using namespace std;
int main(){
    
    vector <int> v(5);
    
    

    for(int i=0;i<5;i++){
        cin>>v[i];
    }
    cout<<"Enter x: ";
    int x;
    cin>>x;

    int occurence = -1;
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]==x){
            occurence = i;
            break;
        }

    }
    cout<<"The last occurence of variable x is at index "<< occurence;
}