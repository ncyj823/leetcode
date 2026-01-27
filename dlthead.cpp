#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node* back;

    public:
    Node(int data1, Node* next1,Node* prev1,Node* back1){
        data = data1;
        next = next1;
        prev = prev1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
        back = nullptr;
    }

    public:
    Node* dlthead(Node* head)
    {
        if(head==NULL|| head->next==NULL)
        return NULL;
    

    Node* prev = head;
    head = head->next;
    head-> back = nullptr;
    head->next = nullptr;
    delete prev;
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
    head->next->back = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->back = head->next;
    cout<<"Original list: ";
    Node node(0);
    node.print(head);
    head = node.dlthead(head);
    cout<<"\nList after deleting head: ";
    node.print(head);
    return 0;
}