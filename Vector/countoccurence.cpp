#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>  v(5);
    for(int i=0;i<5;i++){
        cin>>v[i];
    }
    int x;
    cout<<"Enter x: ";
    cin>>x;
    int occurence = 0;
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            occurence++;
        }
    }
    cout<<occurence;
    return 0;
}
