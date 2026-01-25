#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
Node* remove(Node* head, int el){
    if(head==NULL) 
    return head;
    if(head->data==el)
    {
        Node* temp = head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL)
    {
        if(temp->data==el)
        {
            prev->next=prev->next->next;
            free(temp);
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    return temp;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    cout<<"Original list: ";
    display(head);
    head = remove(head, 4);
    cout<<"List after removing 4: ";
    display(head);
    return 0;
}
    