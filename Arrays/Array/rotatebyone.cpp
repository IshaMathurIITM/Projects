#include<iostream>
using namespace std;

int main(){
    int n=5;
    int a[5] = {1,2,3,4,5};
    int temp=a[4];
    for(int i=3; i>=0; i--){
        a[i+1] = a[i];
    }
    a[0] = temp;
    for(int i=0; i<5; i++){
        cout << a[i] << " ";
    }


    return 0;

}