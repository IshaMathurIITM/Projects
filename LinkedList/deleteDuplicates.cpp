#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }

};

class LinkedList{
public:
    Node* head;

    LinkedList(){
        head = NULL;
    }

    void insertAtTail(int value){
        Node* new_node = new Node(value);
        
        if(head==NULL){
            head = new_node;
            return;
        }

        
    }

};

void deleteDuplicates(Node* &head){

}

int main(){


    return 0;
}