#include <iostream>
using namespace std;
int main(){
    int x;
    cout<<"Enter a number: ";
    cin>>x;
    if(x>80){
        if(x>90){
            cout<<"Super"<<endl;
        }
        else{
            cout<<"Well done"<<endl;
        }
    }
    else if(x>50){
    cout<<"Can improve"<<endl;
    }
    else{
        cout<<"Not good"<<endl;
    }    
    
}