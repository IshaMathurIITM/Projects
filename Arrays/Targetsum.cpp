#include<iostream>
using namespace std;
int main(){
    int a[] = {3,4,6,7,1};
    int x; //x is target sum
    cout<<"Enter x: ";
    cin>>x;
    int pair=0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
        if(a[i]+a[j]==x){
            pair++;
        }
    }
    }
    cout<<pair;

    return 0;

}