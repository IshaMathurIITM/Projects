#include <iostream>
using namespace std;
int main(){
    int m,n;
    cin >>m >>n;

    int array[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> array[i][j];
        }
    }

    int transpose[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            transpose[i][j] =  array[j][i];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}