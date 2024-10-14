#include<iostream>
using namespace std;
int main(){
    int CP,SP,profit, loss;
    cout<<"Enter cost price: ";
    cin>>CP;
    cout<<"Enter selling price: ";
    cin>>SP;
    if(CP<SP){
        profit = SP-CP;
        cout<<"Profit is "<<profit;

    }
    else{
        loss = CP-SP;
        cout<<"Loss is "<<loss;
    }




    return 0;
}