#include<iostream>
using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int x = 10;
    int y = 20;
    int *px = &x;
    int *py = &y;
    swap(px,py);
    cout << x << " " << y << endl;

    return 0;
}