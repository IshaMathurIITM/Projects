#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n=5, x;
    int i=0, j=1;
    cout << "Enter a number: ";
    cin >> x;
    bool flag = false;
    int arr[5] = {5,10,15,20,26};
    while(i<n && j<n){
        if(abs(arr[i]-arr[j]) == x){
            flag = true;
            break;
        }
        else if(abs(arr[i]- arr[j]) < x){
            j++;
        }
        else{
            i++;
        }
    }

    if(flag == true){
        cout << "Yes";
    }
    else{
        cout << "No";
    }





    return 0;
}