#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void spiralOrder(vector<vector<int>> &a){
    int left = 0;
    int right = a[0].size()-1;
    int top = 0;
    int bottom = a.size()-1;

    int direction = 0;
    while(left<=right && top<=bottom){
        // left -> right
        if(direction==0){
            for(int col=left; col<=right; col++){
                cout << a[top][col] << " ";
            }
            top++;
        }
        // top -> bottom
        else if(direction==1){
            for(int row=top; row<=bottom; row++){
                cout << a[row][right] << " ";
            }
            right--;
        }
        // right -> left
        else if(direction==2){
            for(int col=right; col>=left; col--){
                cout << a[bottom][col] << " ";
            }
            bottom--;
        }
        // bottom -> top
        else{
            for(int row=bottom; row>=top; row--){
                cout << a[row][left] << " ";
            }
            left++;
        }
        direction = (direction+1) % 4;
    }

}
int main(){
    int n,m;
    cout << "Enter no. of rows and columns: " <<endl;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    cout << "Enter elements of matrix: " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    cout << "Input matrix: " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Output elements: " << endl;
    spiralOrder(a);
    
    return 0;
}