#include<iostream>
using namespace std;
int main(){
    int x = 18;
    float y = 7.9;
    // create a pointer that can store address of x
    int *ptr = &x;
    cout << "Address stored in ptr: " << ptr << endl;
    cout << "Value present at the address stored in ptr: " << *ptr << endl; // dereference

    //create a pointer that can store address of y
    float *ptr1 = &y;
    cout << ptr1 << endl;

    int *ptr2;
    cout << ptr2 << endl;
    int marks = 90;
    ptr2 = &marks;
    cout << ptr2 << endl;
    cout << *ptr2 << endl;

    
    return 0;
}