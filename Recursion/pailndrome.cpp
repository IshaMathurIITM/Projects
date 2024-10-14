#include <iostream>
using namespace std;


int main(){
    int n = 121;
    
    int rev = n%10;
    n = n/10;
    while(n!=0){
        rev = n%10 + 10*rev;
        n = n/10;
    }
    
    if(rev == n){
        cout << "palindrome";
    }
    else{
        cout << "Not palindrome";
    }

    return 0;

}