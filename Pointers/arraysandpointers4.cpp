#include <iostream>
using namespace std;

int main(){
    int a[3] = {11,12,13};
    int (*p)[3] = &a; // variable p points whole array
    cout << p << " " << a << " " << *p << " " << *a << endl; 
    cout << *(*p) << endl;

    return 0;
}