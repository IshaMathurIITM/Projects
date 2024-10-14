#include<iostream>
using namespace std;
int main(){
    int x = 18;
    int *ptr = &x;
    cout << "Address stored in ptr " << ptr << endl;
    cout << "Value of variable which address is stored in ptr " << *ptr << endl;

    x = 23;
    cout << "The new value of variable x is " << x << endl;
    cout << ptr << endl;
    cout << "ptr pointing to same memory which has 23 instead of 18 " << *ptr << endl;

    int valueAtX = *ptr;
    cout << valueAtX << endl;
    


}