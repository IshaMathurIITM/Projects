#include<iostream>
using namespace std;

class Parent{
public:
    int x;
protected:
    int y;
private:
    int z;
            
};

class child1: public Parent{
    // x will remain public
    // y will remain protected
    // z will not be acessible
};

class child1: private Parent{
    // x will be private
    // y will be private
    // z will not be acessible
};

class child1: protected Parent{
    // x will be protected
    // y will be protected
    // z will not be acessible
};

int main(){
    

    return 0;
}