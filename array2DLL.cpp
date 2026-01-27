#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
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

    Node* convertarray2dll(vector<int> &arr){
        Node* head = new Node(arr[0]);
        Node* prev = head;
        for(int i=1;i<arr.size();i++){
            Node* curr = new Node(arr[i]);
            prev->next = curr;
            curr->prev = prev;
            prev = curr;
        }
        return head;
    }
    void print (Node* head){
        while(head!=NULL)
        {
            cout<< head->data<<" ";
            head = head->next;
        }
    }
};

int main()
{
    vector<int> arr = {10,20,30,40,50};
    Node node(0);
    Node* head = node.convertarray2dll(arr);
    node.print(head);
    return 0;
}

