/*
Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B
of students like butterscotch ice-cream. Write C++ program to store two sets using linked
list. compute and display- a) Set of students who like both vanilla and butterscotch b) Set of
students who like either vanilla or butterscotch or not both c) Number of students who like
neither vanilla nor butterscotch */

#include <iostream>
using namespace std;

class Node
{
    int roll;
    Node *next;

public:
    Node()
    {
        roll = 0;
        next = NULL;
    }
    Node(int x)
    {
        roll = x;
        next = NULL;
    }
    friend class IceCreamSet;
};

class IceCreamSet
{
public:
    Node *start;

    IceCreamSet()
    {
        start = NULL;
    }

    void AddStudent(int x)
    {
        Node *newname = new Node(x);
        if (start == NULL)
        {
            start = newname;
            start->next = NULL;
        }
        else
        {
            Node *temp = start;
            while (temp->next != NULL && temp->roll != x)
            {
                temp = temp->next;
            }
            if (temp->roll == x)
            {
                cout << "Roll number already exist" << endl;
            }
            else
            {
                temp->next = newname;
                newname->next = NULL;
                temp = newname;
            }
        }
    }
    void Add(int rollNo)
    {
        Node *s = new Node(rollNo);
        if (start == NULL)
        {
            start = s;
        }
        else
        {
            s->next = start;
            start = s;
        }
    }
    void deleteset(int x)
    {
        if (start == NULL)
        {
            cout << "Empty list" << endl;
        }
        else if (start->roll == x)
        {
            Node *temp = start;
            start = start->next;
            delete temp;
        }
        else
        {
            Node *prev = NULL, *temp = start;
            while (temp != NULL)
            {
                if (temp->roll == x)
                {
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "Student not in list" << endl;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
            }
        }
    }
    void displayset()
    {
        Node *temp = start;
        while (temp != NULL)
        {
            cout << "roll number :" << temp->roll << "." << endl;
            temp = temp->next;
        }
    }
    IceCreamSet intersection(IceCreamSet list2)
    {
        Node *temp1 = start;
        Node *temp2 = NULL;
        IceCreamSet s;

        while (temp1 != NULL)
        {
            temp2 = list2.start;
            while (temp2 != NULL)
            {
                if (temp1->roll == temp2->roll)
                {
                    s.Add(temp1->roll);
                    break;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return s;
    }

    IceCreamSet unionset(IceCreamSet list2)
    {
        Node *temp1 = start;
        Node *temp2 = list2.start;
        IceCreamSet S;

        while (temp1 != NULL)
        {
            S.Add(temp1->roll);
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            temp1 = start;
            bool ispresent = false;
            while (temp1 != NULL)
            {
                if (temp2->roll == temp1->roll)
                {
                    ispresent = true;
                    break;
                }
                temp1 = temp1->next;
            }
            if (!ispresent)
            {
                S.Add(temp2->roll);
            }
            temp2 = temp2->next;
        }
        return S;
    }

    IceCreamSet onlyone(IceCreamSet i)
    {
        // student eating  only one ice cream and not both
        IceCreamSet s;
        Node *temp2 = i.start;
        Node *temp1 = start;
        while (temp1 != NULL)
        {
            bool ispresent = false;
            temp2 = i.start;
            while (temp2 != NULL)
            {
                if (temp1->roll == temp2->roll)
                {
                    ispresent = true;
                    break;
                }
                temp2 = temp2->next;
            }
            if (!ispresent)
            {
                s.Add(temp1->roll);
            }
            temp1 = temp1->next;
        }
        temp2 = i.start;
        while (temp2 != NULL)
        {
            bool ispresent = false;
            temp1 = start;
            while (temp1 != NULL)
            {
                if (temp2->roll == temp1->roll)
                {
                    ispresent = true;
                    break;
                }
                temp1 = temp1->next;
            }
            if (!ispresent)
            {
                s.Add(temp2->roll);
            }
            temp2 = temp2->next;
        }
        return s;
    }
    void noIceCream(IceCreamSet un)
    {

        int count = 0;
        Node *temp = start; // universal set;
        while (temp != NULL)
        {
            bool ispresent = false;
            Node *temp1 = un.start; // union set
            while (temp1 != NULL)
            {
                if (temp->roll == temp1->roll)
                {
                    ispresent = true;
                    break;
                }
                temp1 = temp1->next;
            }
            if (ispresent == false)
            {
                count = count + 1;
            }
            temp = temp->next;
        }
        cout << count << endl;
    }
};
int main()
{
    IceCreamSet un, v, b;
    int choice;
    int n;
    do
    {
        cout << "<------Details of IceCream------>" << endl;
        cout << "1.All students details:" << endl;
        cout << "2.Vanilla eating students" << endl;
        cout << "3.Butterscotch Eating students" << endl;
        cout << "4.Set of students who like both vanilla and butterscotch" << endl;
        cout << "5.Set of students who like either vanilla or butterscotch or not both" << endl;
        cout << "6.Number of students who like neither vanilla nor butterscotch" << endl;
        cout << "7.Exit" << endl;
        cout << "Enter the choice;" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the number of students:" << endl;
            cin >> n;
            int num;
            for (int i = 0; i < n; i++)
            {
                cout << "enter roll number" << endl;
                cin >> num;
                un.AddStudent(num);
            }
            un.displayset();
        }
        else if (choice == 2)
        {
            cout << "Enter the number of students eating vanilla:" << endl;
            int vn;
            int num;
            cin >> vn;
            for (int i = 0; i < vn; i++)
            {
                cout << "enter roll number" << endl;
                cin >> num;
                v.AddStudent(num);
            }
            v.displayset();
        }
        else if (choice == 3)
        {
            cout << "Enter the number of students eating Butterscotch:" << endl;
            int n;
            cin >> n;
            int num;
            for (int i = 0; i < n; i++)
            {
                cout << "enter roll number" << endl;
                cin >> num;
                b.AddStudent(num);
            }
            b.displayset();
        }
        else if (choice == 4)
        {
            cout << "Set of students who like both vanilla and butterscotch" << endl;
            IceCreamSet i;
            i = b.intersection(v);
            i.displayset();
        }
        else if (choice == 5)
        {
            cout << "Set of students who like either vanilla or butterscotch or not both" << endl;
            IceCreamSet d;
            d = b.onlyone(v);
            d.displayset();
        }
        else if (choice == 6)
        {
            cout << "The students who like neither vanilla nor butterscotch" << endl;
            IceCreamSet a; // union set of both
            a = b.unionset(v);
            un.noIceCream(a);
        }
        else
        {
            cout << "EXIT" << endl;
            break;
        }
    } while (choice < 7);
    return 0;
}