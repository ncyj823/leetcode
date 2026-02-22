#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1,Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }

    Node* deletetail(Node* head){
        Node* tail = head;
        while(tail->next!=NULL)
        {
            tail = tail->next;
        }
        Node* prev = tail->prev;
        tail->prev = nullptr;
        prev->next = nullptr;
        delete tail;
        return head;
    }

    void print(Node* head)
    {
        while(head!=NULL)
        {
            cout<< head->data << " ";
            head = head->next;
        }
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    cout<<"Original list: ";
    Node node(0);
    node.print(head);
    head = node.deletetail(head);
    cout<<"\nList after deleting tail: ";
    node.print(head);
    return 0;
}