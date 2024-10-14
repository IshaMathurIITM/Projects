#include<iostream>
using namespace std;
int main(){

    int a[] = {2,3,1,3,2,4,4,5,6,1};
    int size = 10;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]==a[j]){
                a[i]=a[j]=-1;
            }
        }
    }
    for(int i=0;i<size;i++){
        if(a[i]>0){
            cout<<a[i]<<endl;
        }
    }
    return 0;
}