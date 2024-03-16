#include<iostream>
#include<map>
using namespace std;

class Node{

    public:
    int random;
    int data;
    Node* next;

    // Constructor
    Node(int data){
        this->data = data;
        this->random = random;
        this->next = NULL;
    }

    // Destructor
    ~Node(){
        int value = this -> data;

        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

/*
// 1st Approach

void insertAtTail(Node* &head, Node* &tail, int d){

    Node* newNode = new Node(d);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        tail -> next = newNode;
        tail = newNode;
    }
}

Node* copyLinkedList(Node* head){

    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    while(temp != NULL){
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp -> next;
    }

    map<Node*, Node*> oldToNew;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){
        oldToNew[originalNode] = cloneNode;
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL){
        cloneNode -> random = oldToNew[originalNode -> random];
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }

    return cloneHead;
}
*/

// 2nd Approach

void insertAtTail(Node* &head, Node* &tail, int d){

    Node* newNode = new Node(d);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        tail -> next = newNode;
        tail = newNode;
    }
}

Node* copyLinkedList(Node* head){

    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    while(temp != NULL){
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp -> next;
    }

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){
        Node* next = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = next;

        next = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode = next;
    }

    temp = head;
    while(temp != NULL){
        if(temp -> next != NULL){
            temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
        }
        temp = temp -> next -> next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;

        if(originalNode != NULL){
            cloneNode -> next = originalNode -> next;
        }
        cloneNode = cloneNode -> next;
    }

    return cloneHead;
}

int main(){

    //Clone a Linked List with next and random pointer

    return 0;
}