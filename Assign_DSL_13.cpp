/*
A double-ended queue (deque) is a linear list in which additions and deletions may be made
at either end. Obtain a data representation mapping a deque into a one dimensional array.
Write C++ program to simulate deque with functions to add and delete elements from either
end of the deque.*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class Deque
{
public:
    Node *front;
    Node *rear;

    Deque()
    {
        front = NULL;
        rear = NULL;
    }

    void insertFront(int data)
    {
        Node *newNode = new Node(data);
        if (front!=NULL)
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        else
        {
            front = newNode;
            rear = newNode;
        }
    }

    void insertRear(int data)
    {
        Node *newNode = new Node(data);
        if (front!=NULL)
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        else
        {
            front = newNode;
            rear = newNode;
        }
    }

    void deleteFront()
    {
        if (front!=NULL)
        {
            Node *temp = front;
            front = front->next;
            if (front!=NULL)
            {
                front->prev = NULL;
            }
            else
            {
                rear = NULL;
            }
            delete temp;
        }
        else
        {
            cout << "Underflow" << endl;
        }
    }

    void deleteRear()
    {
        if (front!=NULL)
        {
            Node *temp = rear;
            rear = rear->prev;
            if (rear!=NULL)
            {
                rear->next = NULL;
            }
            else
            {
                front = NULL;
            }
            delete temp;
        }
        else
        {
            cout << "Underflow" << endl;
        }
    }

    void print()
    {
        Node *newNode = front;
        if (front!=NULL)
        {
            while (newNode)
            {
                cout << newNode->data << " ";
                newNode = newNode->next;
            }
            cout << endl;
        }
        else
        {
            cout << "Underflow";
        }
    }
};

int main()
{
    Deque dq;
    int choice;
    while (true)
    {
        cout << "MENU" << endl;
        cout << "1.Insert at front" << endl;
        cout << "2.Insert at rear" << endl;
        cout << "3.Delete from front" << endl;
        cout << "4.Delete from rear" << endl;
        cout << "5.Print" << endl;
        cout << "6.Exit" << endl;
        cout<<"Enter your choice:"<<endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int key;
            cout << "Enter element ";
            cin >> key;
            dq.insertFront(key);
            break;
        }
        case 2:
        {
            int key;
            cout << "Enter element ";
            cin >> key;
            dq.insertRear(key);
            break;
        }
        case 3:
        {
            dq.deleteFront();
            break;
        }
        case 4:
        {
            dq.deleteRear();
            break;
        }
        case 5:
        {
            dq.print();
            break;
        }
        case 6:
        {
            exit(0);
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
}