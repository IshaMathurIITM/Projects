#include<iostream>
using namespace std;

class Parent1{ // single inheritance
public:
    Parent1(){
        cout << "Parent1 class" << endl;
    }    
};

class Parent2{
public:
    Parent2(){
        cout << "Parent2 class" << endl;
    }    
};

class Child: public Parent1, public Parent2{ // multiple inheritance
public:
    Child(){
        cout << "Child class" << endl;
    }    
};

class Grandchild: public Child{ // multi-level inheritance
public:
    Grandchild(){
        cout << "Grandchild class" << endl;
    }    
};

int main(){
    Grandchild c;
    


    return 0;
}