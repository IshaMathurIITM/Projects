#include<iostream>
using namespace std;
// int largestElementIndex(int array[], int size){
//     int max = 0;
//     int maxindex = -1;
//     for(int i=0;i<size;i++){
//         if(array[i]>max){
//             max = array[i];
//             maxindex = i;
//         }
//     }
//     return maxindex;

// }

// int main(){
//     int array[] = {2,3,5,7,6,1,7};
//     int n = 7;
//     int indexoflargest = largestElementIndex(array,n);
//     int largestelement = array[indexoflargest];
//     cout<<largestelement<<endl;
//     for(int i=0;i<n;i++){
//         if(array[i]==largestelement){
//             array[i] = -1;
//         }
//     }
    
//     int indexofsecondlargest = largestElementIndex(array,n);
//     cout<<array[indexofsecondlargest]<<endl;
//     return 0;
// }
int secondLargestElement(int array[], int size){
    int max = 0;
    int second_max = 0;
    for(int i=0;i<size;i++){
        if(array[i]>max){
            max = array[i];
        }

    }
    for(int i=0;i<size;i++){
        if(array[i]>second_max && array[i]!=max){
            second_max = array[i];
        }
    }
    return second_max;
}

int main(){
    int array[] = {2,3,5,7,6,1,7};
    int n = 7;
    cout<<secondLargestElement(array,n);
}