#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a[] = {1,2,3,5,4};
    bool sortedflag = true;
    for(int i=1;i<5;i++){
        if(a[i]<=a[i-1]){
            sortedflag = false;
        }
        
    }
    cout<<sortedflag<<endl;
    return 0;
}