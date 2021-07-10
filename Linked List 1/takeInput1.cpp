//C++ program to input and print a single linked list.
#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

//take input function
//terminates when we enter -1
Node* takeInput()
{
    int data;
    cin >> data;
    Node* head = NULL;
    while(data != -1)
    {
        Node* newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cin >> data;
    }
    return head;
}

//function to print linked list elements
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
}

//main function
int main()
{
    Node* head = takeInput();
    print(head);
    return 0;
}
