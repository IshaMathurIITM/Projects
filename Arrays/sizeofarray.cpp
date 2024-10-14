#include<iostream>
using namespace std;
int main(){
    int array[] = {1,2,3,4,5};
    //size of array
    cout<<sizeof(array)<<endl;
    int length = sizeof(array)/sizeof(array[0]);
    cout<<length<<endl;

    //for loop
    for(int idx=0;idx<length;idx++){
        cout<<array[idx]<<endl;
    }
    
    //for each loop
    for(int ele:array){
        cout<<ele<<endl;
    }

    //while loop
    int idx=0;
    while(idx<length){
        cout<<array[idx]<<endl;
        idx++;
    }


    return 0;
}