#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int leftMostone(vector<vector<int>> &V){

    int leftMostOne = -1;
    int maxOnesRow = -1;
    int j=V.size()-1;

    // finding leftmost one in 0th row
 while(j>=0 && V[0][j]==1){
    maxOnesRow = 0;
    leftMostOne = j;
    j--;
}

// check if other rows have a one left to the leftmost one
for(int i=1; i<V.size(); i++){
    while(j>=0 && V[i][j]==1){
        leftMostOne = j;
        maxOnesRow = i;
        j--;
    }

}
return maxOnesRow;
}


// int maximumOnesRow(vector<vector<int>> &V){
//     int maxOnes = INT_MIN;
//     int maxOnesRow = -1;
//     int columns = V[0].size();
//     for(int i=0; i<V.size(); i++){
//         for(int j=0; j<V[i].size(); j++){
//             if(V[i][j] == 1){
//                 int numberOfOnes = columns - j; // j = first occurence
//                 if(numberOfOnes > maxOnes){
//                     maxOnes = numberOfOnes;
//                     maxOnesRow = i;
//                 }
//                 break;
//             }
//         }
//     }
//     return maxOnesRow;
// }
int main(){
    int m,n;
    cin >>n >> m;
vector<vector<int>> vec(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> vec[i][j];
        }
    }

    int res = leftMostone(vec);
    cout << res << endl;



}