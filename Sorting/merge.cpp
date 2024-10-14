#include<iostream>
#include<vector>
using namespace std;

int main(){
    int num1[] = {5,8,10};
    int n1 = sizeof(num1)/sizeof(num1[0]);
    int num2[] = {2,7,8};
    int n2 = sizeof(num2)/sizeof(num2[0]);

    vector<int> num(n1+n2);

    int i=0, j=0, k=0;
    while(i<n1 && j<n2){
        if(num1[i]<num2[j]){
            num[k++] = num1[i++];
        }
        
        else{
            num[k++] = num2[j++];
        }
    }

    while(i<n1){
        num[k++] = num1[i++];
    }

    while(j<n2){
        num[k++] = num2[j++];
    }

    for(int p=0;p<(n1+n2); p++){
        cout << num[p] << " ";
    }



    return 0;
}