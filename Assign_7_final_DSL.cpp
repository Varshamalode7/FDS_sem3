/////***8888888*??///??/////
/*
    Write C++ program for storing binary number using doubly linked lists. Write
    functions- a) To compute 1‘s and 2‘s complement b) Add two binary numbers
*/

#include <iostream>
using namespace std;
class Node
{
    Node *prev;
    Node *next;
    int data;

public:
    Node()
    {
        prev = NULL;
        next = NULL;
        data = 0;
    }

    Node(int d)
    {
        prev = NULL;
        next = NULL;
        data = d;
    }
    friend class Bnr;
};

class Bnr
{
    Node *head;
    Node *tail;

public:
    Bnr()
    {
        head = NULL;
        tail = NULL;
    };

    void fun_insertatf(int d)
    {
        if (head == NULL)
        {
            Node *newnode = new Node(d);
            head = newnode;
            tail = newnode;
        }
        else
        {
            Node *newnode = new Node(d);
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }
    }

    void fun_createBN(int n1)
    {
        int temp = n1;
        while (temp > 0)
        {
            int r = temp % 2;
            temp = temp / 2;
            fun_insertatf(r);
        }
    }

    void fun_display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    Bnr fun_1comple()
    {
        Bnr obj1;

        Node *temp = tail;
        while (temp != NULL)
        {
            if (temp->data == 0)
            {
                obj1.fun_insertatf(1);
            }
            else
            {
                obj1.fun_insertatf(0);
            }
            temp = temp->prev;
        }
        return obj1;
    }

    Bnr fun_add(Bnr n2)
    {
        Bnr obj_sum;
        Node *temp1 = tail;
        Node *temp2 = n2.tail;
        int carry = 0;
        while (temp1 != NULL && temp2 != NULL)
        {
            int sum1 = temp1->data ^ temp2->data ^ carry;
            carry = (temp1->data && temp2->data) || (temp1->data && carry) || (temp2->data && carry);
            obj_sum.fun_insertatf(sum1);
            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }

        while (temp1 != NULL)
        {
            int sum1 = temp1->data ^ carry;
            carry = (temp1->data && carry);
            obj_sum.fun_insertatf(sum1);
            temp1 = temp1->prev;
        }
        while (temp2 != NULL)
        {
            int sum1 = temp2->data ^ carry;
            carry = (temp2->data && carry);
            obj_sum.fun_insertatf(sum1);
            temp2 = temp2->prev;
        }
        if (carry == 1)
        {
            obj_sum.fun_insertatf(carry);
        }
        return obj_sum;
    }

    Bnr fun_2comple()
    {
        Bnr obj2;
        Bnr obj3;
        obj2 = fun_1comple();
        obj3.fun_insertatf(1);

        return obj2.fun_add(obj3);
    }
};
int main()
{

    Bnr obj1;
    while (true)
    {
        cout << "***********************************************" << endl;
        cout << "enter 1 for create binary number" << endl;
        cout << "enter 2 for display binary number" << endl;
        cout << "enter 3 for displaying 1s complement binary number" << endl;
        cout << "enter 4 to add number " << endl;
        cout << "enter 5 to find 2's complement " << endl;
        cout << "enter 6 to exite " << endl;
        cout << "enter here : ";
        int flag;
        cin >> flag;
        cout << "***********************************************" << endl;
        switch (flag)
        {
        case 1:
        {

            cout << "enter number convert it into binary number : ";
            int n1;
            cin >> n1;
            obj1.fun_createBN(n1);

            break;
        }
        case 2:
        {
            cout << "binary no. is : ";
            obj1.fun_display();
            cout << endl;
            break;
        }
        case 3:
        {
            cout << "1's complement of binary no. is : ";
            obj1.fun_1comple().fun_display();
            cout << endl;
            break;
        }
        case 4:
        {
            Bnr obj2;
            cout << "enter another number to add binary number : ";
            int n1;
            cin >> n1;
            cout << endl;
            obj2.fun_createBN(n1);
            cout << "addition of binary no. is : ";
            obj1.fun_add(obj2).fun_display();
            cout << endl;
            break;
        }

        case 5:
        {
            cout << "2's complement of binary no. is : ";
            obj1.fun_2comple().fun_display();
            cout << endl;
            break;
        }
        }
        if (flag == 6)
        {
            cout << "exited....... " << endl;
            break;
        }
    };
    return 0;
}


/*The ticket booking system of Cinemax theater has to be implemented using C++
program. There are 10 rows and 7 seats in each row. Doubly circular linked list has to be
maintained to keep track of free seats at rows. Assume some random booking to start
with. Use array to store pointers (Head pointer) to each row. On demand
a) The list of available seats is to be displayed
b) The seats are to be booked
c) The booking can be cancelled.
 */

// #include <iostream>
// #include <stdlib.h>
// using namespace std;
// class node
// {
// public:
//     node *next;
//     node *prev;
//     int seat;
//     string id;
//     int status;
// };
// class cinemax
// {
// public:
//     node *head, *tail, *temp;
//     cinemax()
//     {
//         head = NULL;
//     }
//     void create_list();
//     void display();
//     void book();
//     void cancel();
//     void avail();
// };
// void cinemax::create_list()
// {
//     int i = 1;
//     temp = new node;
//     temp->seat = 1;
//     temp->status = 0;
//     temp->id = "null";
//     tail = head = temp;
//     for (int i = 2; i <= 70; i++)
//     {
//         node *p;
//         p = new node;
//         p->seat = i;
//         p->status = 0;
//         p->id = "null";
//         tail->next = p;
//         p->prev = tail;
//         tail = p;
//         tail->next = head;
//         head->prev = tail;
//     }
// }
// void cinemax::display()
// {
//     {
//         int r = 1;
//         node *temp;
//         temp = head;
//         int count = 0;

//         while (temp->next != head)
//         {
//             if (temp->seat / 10 == 0)
//                 cout << "S0" << temp->seat << " :";
//             else
//                 cout << "S" << temp->seat << " :";

//             if (temp->status == 0)
//                 cout << "|___| ";
//             else
//                 cout << "|_B_| ";
//             count++;
//             if (count % 7 == 0)
//             {
//                 cout << endl;
//                 r++;
//             }
//             temp = temp->next;
//         }
//         cout << "S" << temp->seat << " :";
//         if (temp->status == 0)
//             cout << "|___| ";
//         else
//             cout << "|_B_| ";
//     }
// }
// void cinemax::book()
// {
//     int x;
//     string y;
// label:
//     cout << "\n\n\nEnter seat number to be booked\n";
//     cin >> x;
//     cout << "Enter your ID number\n";
//     cin >> y;
//     if (x < 1 || x > 70)
//     {
//         cout << "Enter correct seat number to book (1-70)\n";
//         goto label;
//     }
//     node *temp;
//     temp = new node;
//     temp = head;
//     while (temp->seat != x)
//     {
//         temp = temp->next;
//     }

//     if (temp->status == 1)
//         cout << "Seat already booked!\n";
//     else
//     {
//         temp->status = 1;
//         temp->id = y;
//         cout << "Seat " << x << " booked!\n";
//     }
// }
// void cinemax::cancel()
// {
//     int x;
//     string y;
// label1:
//     cout << "Enter seat number to cancel booking\n";
//     cin >> x;
//     cout << "Enter you ID\n";
//     cin >> y;
//     if (x < 1 || x > 70)
//     {
//         cout << "Enter correct seat number to cancel (1-70)\n";
//         goto label1;
//     }
//     node *temp;
//     temp = new node;
//     temp = head;
//     while (temp->seat != x)
//     {
//         temp = temp->next;
//     }
//     if (temp->status == 0)
//     {
//         cout << "Seat not booked yet!!\n";
//     }
//     else
//     {
//         if (temp->id == y)
//         {
//             temp->status = 0;
//             cout << "Seat Cancelled!\n";
//         }

//         else
//             cout << "Wrong User ID !!! Seat cannot be cancelled!!!\n";
//     }
// }
// void cinemax::avail()
// {
//     int r = 1;
//     node *temp;
//     temp = head;
//     int count = 0;
//     cout << "\n\n\n\n";

//     cout << " Screen this way \n";

//     while (temp->next != head)
//     {
//         {
//             if (temp->seat / 10 == 0)
//                 cout << "S0" << temp->seat << " :";
//             else
//                 cout << "S" << temp->seat << " :";
//             if (temp->status == 0)
//                 cout << "|___| ";
//             else if (temp->status == 1)
//                 cout << " ";

//             count++;
//             if (count % 7 == 0)

//             {

//                 cout << endl;
//             }
//         }
//         temp = temp->next;
//     }
//     if (temp->status == 0)
//     {
//         cout << "S" << temp->seat << " :";

//         if (temp->status == 0)
//             cout << "|___| ";
//     }
// }
// int main()
// {
//     cinemax obj;
//     obj.create_list();
//     int ch;
//     char c = 'y';
//     while (c == 'y')
//     {
//         obj.display();

//         cout << "\nEnter Choice\n1.Current SeatStatus\n2.Book Seat \n3.Available Seat\n4.CancelSeat\n";
//         cin >> ch;
//         switch (ch)
//         {
//         case 1:
//             obj.display();
//             break;
//         case 2:
//             obj.book();
//             break;
//         case 3:
//             obj.avail();
//             break;
//         case 4:
//             obj.cancel();
//             break;
//         default:
//             cout << "Wrong choice input\n";
//         }
//         cout << "\nDo you want to perform any other operation : (y/n)\n";
//         cin >> c;
//     }
//     return 0;
// }

