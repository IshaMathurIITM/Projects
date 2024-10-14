#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a[] = {1,2,3,4,5};
    int evensum = 0;
    int oddsum = 0;
    for(int i=0;i<5;i++){
        if(i%2==0){
            evensum = evensum + a[i];
        }
        else{
            oddsum = oddsum + a[i];
        }
    }
    cout<<"The sum of even indices is: "<<evensum<<endl;
    cout<<"The sum of odd indices is: "<<oddsum<<endl;
    cout<<"Difference is: "<<evensum-oddsum;





    return 0;
}