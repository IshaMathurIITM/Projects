#include<iostream>
using namespace std;
int main(){
    int x,y;
    cin >>x >>y;

    int *ptrx = &x;
    int *ptry = &y;

    int result;

    int *ptr_result = &result;

    /* *ptrx -> 10
    *ptry -> 20
    *ptrx + *ptry = 30
    *ptr_result = 30  
    */
    *ptr_result = *ptrx + *ptry;
    cout << result << " " << *ptr_result << endl;

    return 0;
}