#include<iostream>
#include<vector>
using namespace std;
int main(){

    vector<int> v;

    //for loop
    for(int i=0;i<5;i++){
        int element;
        cin>>element;
        v.push_back(element);


    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    //for each loop
    for(int ele:v){
        cout<<ele<<" ";
    }
    cout<<endl;

    // while loop
    int i=0;
    while(i<v.size()){
        cout<<v[i]<<" ";
        i++;
    }
    cout<<endl;

    v.insert(v.begin()+2,6);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    v.erase(v.end()-2);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;


    return 0;
}