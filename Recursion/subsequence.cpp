#include <iostream>
#include <vector>
using namespace std;

void f(string &str, int i, string result, vector<string> &li){
    //base case
    if(i == str.length()){
        li.push_back(result);
        return;
    }
    f(str, i+1, result+str[i], li);
    f(str, i+1, result, li);
}


int main(){
    string str = "abc";
    vector<string> li;
    
    f(str, 0, " ", li);
    for(int i=0; i<li.size(); i++){
        cout << li[i] << " ";
    }



    return 0;
}