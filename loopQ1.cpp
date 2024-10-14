#include<iostream>
using namespace std;
int main(){
    int a,b; // find a^b
    cout<<"Enter first number: ";
    cin>>a; // a is base
    cout<<"Enter second number: ";
    cin>>b; // b is power
    int power = 1;
    for(int i=1;i<=b;i++){
        
        power = power * a;


    
    cout<<a<<" raised to the power " <<i<< " is: "<<power<<endl;
    }




    return 0;
}