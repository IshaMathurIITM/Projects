#include<iostream>
using namespace std;
int main(){
    int x,y,z;
    cout<<"Enter first number: ";
    cin>>x;
    cout<<"Enter second number: ";
    cin>>y;
    cout<<"Enter third number: ";
    cin>>z;
    if(x>y && x>z){
        cout<<"Maximum of these three numbers is "<<x<<endl;
    }
    else if(y>x && y>z){
        cout<<"Maximum of these three numbers is "<<y<<endl;
    }
    else{
        cout<<"Maximum of these three numbers is "<<z<<endl;
    }
    
    
    
}
