#include <iostream>
#include <vector>
using namespace std;


void f(string &str, int i, string result, vector<string> li){
    if(i == str.size()){
        //cout << result << "\n"
        li.push_back(result);
        return;
    }
    int digit = str[i] - '0';
    if(digit <= 1){
        

    }


}