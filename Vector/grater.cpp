#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v(5);
    for(int i=0;i<5;i++){
        cin>>v[i];
    }
    int x;
    cout<<"Enter x: ";
    cin>>x;
    int count = 0;
    for(int i=0;i<v.size();i++){
        if(v[i]>x){
            count++;
            
        }
    }
    cout<<count<<" elements are greater than "<<x<<" in this vector";


    return 0;
}