#include<iostream>
using namespace std;
int main(){
    int array[] = {3,7,18,9,5};
    int n; // n is to be search in array
    cout<<"Enter a number: ";
    cin>>n;
    int ans = -1;
    int length = sizeof(array)/sizeof(array[0]);
    for(int i=0;i<length;i++){
        if(array[i]==n){
            ans = i; // i is the index of the number
        }
        
        
    }
    cout<<ans;


    return 0;
}