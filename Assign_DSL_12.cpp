/*Write program to implement a priority queue in C++ using an order list/array to store the
items in the queue. Create a class that includes the data items (which should be template)
and the priority (which should be int). The order list/array should contain these objects, with
operator <= overloaded so that the items with highest priority appear at the beginning of the
list/array (which will make it relatively easy to retrieve the highest item.)*/

#include <iostream>
using namespace std;
const int Max = 20;
const int limit = 5;

template <class T, class S>
class item
{
public:
    T priority;
    S item_title;
    item()
    {
        priority = -1;
        item_title = "";
    }
    item(T p, S j)
    {
        this->priority = p;
        this->item_title = j;
    }
    friend class Queue;
    bool operator<=(item &obj)
    {

        if (obj.priority > priority)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Queue
{
    item<int, string>
        arr[Max];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void insert_q(int p, string name)
    {
        if (rear == Max - 1)
        {
            cout << "overflow...! \n";
        }
        // item val(name,p);
        item<int, string>
            val(p, name);
        if (front == -1)
        {
            front++;
        }
        rear++;
        int j = rear - 1;
        while (j >= 0 && val <= arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
    void del()
    {
        if (front == -1)
        {
            cout << "No item entries \n";
            return;
        }
        item<int, string>
            item = arr[front];
        front++;
        cout << "___________: Deleted Successfully :___________\n";
        cout << "\t"
             << "item title :" << item.item_title << endl;
        cout << "\t"
             << "item Priority : " << item.priority << endl;
    }
    void display_q()
    {
        if (arr[front].priority == -1 || front == -1)
        {
            cout << "\tNo item entries " << endl;
        }
        else
        {

            cout << "________________________________________\n";
            cout << endl;
            cout << " item title  \t"
                 << "item Priority : "
                 << "\n";
            for (int i = front; i <= rear; i++)
            {
                cout << " " << arr[i].item_title << "             " << arr[i].priority << "\n";
            }
            cout << "________________________________________\n";
        }
    }
};
int main()
{
    Queue q;
    while (true)
    {
        cout << "\n____________ MENU ____________\n";
        cout << "\n1.Add the job \n2.Delete item\n3.Display item\n4.EXIT...";
        cout << "\n______________________________\n";
        int choice;
        cout << "Enter Choice : \n";
        cin >> choice;
        if (choice == 1)
        {
            string s;
            cout << "Enter the name of job : " << endl;
            cin >> s;
            int n;
            cout << "Enter its priority : " << endl;
            cin >> n;
            q.insert_q(n, s);
            cout << "\nSelected Successfully !\n";
        }
        else if (choice == 2)
        {
            q.del();
        }
        else if (choice == 3)
        {
            q.display_q();
        }
        else if (choice == 4)
        {
            cout << "--->Thanks for using program <---" << endl;
            break;
        }
        else
        {
            cout << "INVALID CHOICE...!" << endl;
        }
    }

    return 0;
}
