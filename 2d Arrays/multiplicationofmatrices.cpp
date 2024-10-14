#include<iostream>
using namespace std;
int main(){
    int r1,c1;
    cout << "Enter number of rows of first matrix: ";
    cin >> r1;
    cout << "Enter number of columns of first matrix: ";
    cin >> c1;

    int A[r1][c1];
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cin >> A[i][j];
        }
    }

    int r2,c2;
    cout << "Enter number of rows of second matrix: ";
    cin >> r2;
    cout << "Enter number of columns of second matrix: ";
    cin >> c2;

    int B[r2][c2];
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            cin >> B[i][j];
        }
    }

    int C[r1][c2];
    for(int i=1; i<r1; i++){
        for(int j=1; j<c2; j++){
            int value = 0;
            for(int k=1; k<c1; k++){
                value += A[i][k] * B[k][j];
            }
            C[i][j] = value;
        }
    }

    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }



    
}