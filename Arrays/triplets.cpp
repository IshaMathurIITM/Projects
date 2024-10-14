#include<iostream>
using namespace std;
int main(){
    int a[] = {3,1,2,4,0,6};
    int size = 6;
    int x;
    cout<<"Enter x: ";
    cin>>x;
    int triplets = 0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            for(int k=j+1;k<size;k++){
                if(a[i]+a[j]+a[k]==x){
                    triplets++;
                }
            }
        }
    }
    cout<<triplets;



    return 0;
}