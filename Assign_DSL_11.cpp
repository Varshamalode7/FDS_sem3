/*
Queues are frequently used in computer programming, and a typical example is the creation
of a job queue by an operating system. If the operating system does not use priorities, then
the jobs are processed in the order they enter the system. Write C++ program for simulating
job queue. Write functions to add job, display job and delete job from queue.*/

#include <iostream>
using namespace std;

class Queue
{
private:
    int front, rear;
    int size;
    int *Q;
public:
    Queue()
    {
        size = 0;
        front = -1;
        rear = -1;
        Q = new int[0];
    }
    Queue(int x)
    {
        size = x;
        front = -1;
        rear = -1;
        Q = new int[size];
    }
    void addjob()
    {
        int job;
        cout << "Enter the job number:" << endl;
        cin >> job;
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
                Q[front] = job;
            }
            rear = rear + 1;
            Q[rear] = job;
        }
    }
    void deletejob()
    {
        if (front == -1 || front == rear + 1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            int key;
            key = Q[front];
            front = front + 1;
            cout << "Deleted job :" << key << endl;
        }
    }
    void displayjob()
    {
        cout << "The Job queue is as follow:" << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << "job is:" << Q[i] << endl;
        }
    }
};
int main()
{
    int n;
    cout << "Enter the size of Queue:" << endl;
    cin >> n;
    Queue j(n);

    cout << "<-----MENU------>" << endl;
    cout << "1.Add Jobs in the queue" << endl;
    cout << "2.Delete the job from queue" << endl;
    cout << "3.Display the jobs" << endl;
    cout << "4.Exit" << endl;
    while (true)
    {
        int choice;
        cout << "Enter the choice:" << endl;
        cin >> choice;
        if (choice == 1)
        {
            j.addjob();
        }
        else if (choice == 2)
        {
            j.deletejob();
        }
        else if (choice == 3)
        {
            j.displayjob();
        }
        else
        {
            cout << "EXIT" << endl;
            break;
        }
    }
    return 0;
}
