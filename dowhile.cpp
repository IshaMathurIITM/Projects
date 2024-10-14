#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int sum=0;
    do{
    
        sum +=N;
        N--;
    }while(N>0);
    cout<<sum<<endl;
    return 0;
}