// Assessment 1...
/*In a Network System, where there are multiple networks,  you probably share a printer with other users... 
When you request to print a file, your request is added to the print queue. When your request reaches the 
front of the print queue, your file is printed... This ensures that only one person at a time has access 
to the printer and that this access is given on a first-come, first-served basis... Design an algorithm 
for this scenario and implement your algorithm...*/
#include <iostream>
using namespace std;
class Node      // Class for defining Node attributes
{
    public:
        int person;   // Person serial number
        Node* next;   // Next pointer
    public:
        Node(int val)       // Parametrized Constructor
        {
            person = val;
            next = NULL;
        }
};
class Queue     // Class for Implementation of Queue Data Structure
{
    public:
        Node* front;   // Front pointer
        Node* back;    // Back pointer
        Queue()
        {
            front = NULL;
            back = NULL;
        }
    public:
        void Enqueue(int value)   // Enqueue Operation( Adding Node in the Queue at the time )
        {
            Node* n = new Node(value);
            if(front == NULL)   // If Queue is empty
            {
                front = n;
                back = n;
                return;     // Come out of the function
            }    // Otherwise
            back -> next = n;    // Adding at the back
            back = n;
        }
        void Dequeue()    // Dequeue Operation ( Removing Node from the Queue at the time )
        {
            if(front == NULL)    // If empty, then no Node can be dequeued
            {
                cout << "Queue Underflow Condition !!" << endl;
                return;
            }
            Node* temp = front;     // Removing from the front
            front = temp -> next;
            delete temp;
        }
        void PrintQueue()    // Printing the Queue
        {
            Node* temp = front;
            cout << "\t QUEUE:" << endl;
            if(temp == NULL)
            {
                cout << "Front <--- \t EMPTY \t ---> Back" << endl;
                return;
            }
            if(temp != NULL)
            {
                cout << " Front <--- \t";
                cout << temp -> person << "\t";
                temp = temp -> next;
            }
            for(; temp != NULL; temp = temp -> next)
            {
                cout << temp -> person << "\t";
            }
            cout << "---> Back" << endl;
        }
};
int main()
{
    Queue queue;     // Object creation of Queue class
    int s, x = 0;
    cout << "Enter the number of Operations to perform in the Algorithm : ";
    cin >> s;     // Entering the number of Operations to perform in the Algorithm 
    string str;
    for(int i = 0; i < s; i++)
    {
        cout << "Do you want to Print ? (Y/N) ";  // Enqueuing Operation
        cin >> str;
        if(str == "Y" || str == "y")
        {
            queue.Enqueue(x);        // O(1) time..
            x++;
            queue.PrintQueue();    // Displaying Queue after update O(n) time..
        }
        cout << "Is your Job Done ? (Y/N) ";    // Dequeuing Operation
        cin >> str;
        if(str == "Y" || str == "y")    
        {
            queue.Dequeue();           // O(1) time..
            queue.PrintQueue();    // Displaying Queue after update O(n) time..
        }
    }
    return 0;   // End of the program
}