#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;

    cout<<"Enter an operator(+,-,*,/,%): ";
    char sign;
    cin>>sign;
    switch(sign){
        case '+':
           cout<<"Sum is: "<<a+b<<endl;
           break;
        case '-':
           cout<<"Difference is: "<<a-b<<endl;
           break;
        case '*':
           cout<<"Product is: "<<a*b<<endl;
           break;
        case '/':
           cout<<"Division is: "<<a/b<<endl;
           break; 
        case '%':
           cout<<"Remainder is: "<<a%b<<endl;
           break;
        cout<<"Enter a valid operator"<<endl;              
    }


}