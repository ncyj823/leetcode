#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node* back;
    Node* front;

    public:
    Node(int data1, Node* next1,Node* prev1,Node* back1,Node* front1){
        data = data1;
        next = next1;
        prev = prev1;
        back = back1;
        front = front1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
        back = nullptr;
        front = nullptr;
    }

    public:
    Node* deleteKthposition(Node* head){
        if(head==NULL|| head->next==NULL)
        return NULL;
        Node* temp = head;
        int count = 0;
        while (temp != NULL){
            count++;
            if (count == 0) break;
            temp = temp->next;
        }
        prev = temp->back;
        front = temp->next;

        if (prev== NULL || front == NULL)
        {
            delete temp;
            return NULL;
        }
        else if (prev==NULL)
        {
            front->back = NULL;
            head = front;
            delete temp;
            return head;
        }
        else if (front==NULL)
        {
            prev->next = NULL;
            delete temp;
            return head;
        }
        else
        {
            prev->next = front;
            front->back = prev;
            delete temp;
            return head;
        }
        

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
    Node node(3);
    node.print(head);
    head = node.deleteKthposition(head);
    cout<<"\nList after deleting kth position: ";
    node.print(head);
    return 0;
}