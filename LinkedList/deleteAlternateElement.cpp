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

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    } 

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout << temp->val << "->";
            temp = temp->next;
        }cout << "NULL" << endl;
    }   
};

void deleteAlternateNodes(Node* &head){
    Node* curr = head;
    while(curr!=NULL && curr->next!=NULL){
        Node* temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
        curr = curr->next;
    }
}

int main(){

    LinkedList ll;
    for(int i=1; i<=6; i++){
        ll.insertAtTail(i);
    }
    ll.display();
    deleteAlternateNodes(ll.head);
    ll.display();



    return 0;
}
