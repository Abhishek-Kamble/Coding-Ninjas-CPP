/*
Problem: Insert Node at i-th position
*/
#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

//SOLUTION
int length(Node* head)
{
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

void insertAtIth(Node* head, int pos, int data)
{
	if(len < pos)
		return;
    int len = length(head);
	Node *tempNode = new Node(data);

	if(pos == 0)
	{
		tempNode -> next = head;
		head = newNode;
		return head;
	}

	Node *temp = head;
	int i=1;
	while(i < pos-1 && temp!=NULL)
	{
		temp = temp->next;
		i++;
	}

	tempNode->next = temp->next;
	temp->next = tempNode;
	return;
}

//print ith node of LL
void printIthNode(Node* head, int pos)
{
	int len = length(head);
	if(len<pos)
		return;

	int i=0;
	Node* temp = head;
	while(i<pos-1)
	{
		temp = temp->next;
		i++;
	}

	cout << temp->data;
}

//printing whole LL
void print(Node* head)
{
	Node* temp = head;

	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int pos, data;
		cin >> pos >> data;
        insertAtIth(head, pos, data);
		print(head);
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}
