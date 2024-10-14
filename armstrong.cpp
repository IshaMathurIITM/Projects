#include<iostream>
using namespace std;
int main(){
    int n = 500;
    int sum = 0;
    int product = 1;
    for(int i=1; i<=n; i++){
        while(n!=0){
            int ld = n%10;
            product = ld * ld * ld;
            sum = product + sum;
            {
                if(sum == n){
                    cout<<n<<endl;
                }
            }
            
        }
    }

    
    return 0;
}