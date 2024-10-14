#include<iostream>
using namespace std;

int main(){
    int n=5,k;
    cin >> k;
    int a[5] = {1,2,3,4,5};
    for(int i=n-1; i>=(n-k); i--){
        cout << a[i] << " ";
    }
    for(int i=0; i<(n-k); i++){
        cout << a[i] << " ";
    }






    return 0;
}