#include<iostream>
using namespace std;
int main(){
    int x,y,z;
    cout<<"Enter three numbers ";
    cin>>x>>y>>z;
    if(x>y){
        if(x>z){
            cout<<"Maximum of numbers is "<<x<<endl;
        }
        else{
            cout<<"Maximum of numbers is "<<z<<endl;
        }
    }else //y>x
    {
        if(y>z){
            cout<<"Maximum of numbers is "<<y<<endl;
        }
        else{
            cout<<"Maximum of numbers is "<<z<<endl;
        }
    }
    

}