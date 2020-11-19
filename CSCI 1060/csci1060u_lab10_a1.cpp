//Andrew Murdoch
//CSCI 1060U
//csci1060u_lab10_a1.cpp
//2018-11-29

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// TODO: Create a struct containing a string (element_name)as well as a node pointer (Node* next)
struct Node
{
    //Declaring value being queued
    string element;
    Node* next;
};

// Queue class
class Queue
{
    // --- public members ---
    public:
    // TODO: Constructor (with no parameters) - Creates an empty queue.
    Queue();
    // TODO: Deconstructor - Deletes the queue.
    ~Queue();
    // TODO: isEmpty - Checks if the queue is empty.
    bool isEmpty();
    // TODO: Enqueue - Adds a new Node to the Queue. The new Node should be added to the back of the queue.
    void Enqueue(string element);
    // TODO: Dequeue - Deletes a Node from the Queue. The Node deleted should be from the front of the queue (and it should return the element_name of the deleted Node)
    void Dequeue();
    // TODO: toString - Returns a string containing the contents of the queue from the back Node to the front Node. For example:
    //           [Cat] -> [Dog] -> [Fish]
    string toString();
    // --- private members ---
    private:
    // TODO: Node* front - a pointer to the front of the Queue
    Node* front;
    // TODO: Node* back - a pointer to the back of the Queue
    Node* back;
};

Queue::Queue()
{
    //Creating Empty q back and front
    front = NULL;
    back = NULL;
}

Queue::~Queue()
{
    //While q is not empty deqeue all elements (delete elements)
    while (!isEmpty())
    {
        Dequeue();
    }
}

bool Queue::isEmpty()
{
    //Return true if queue has nothing in it else return false
    return (front == NULL);
}

void Queue::Enqueue(string element)
{
    //Create temporary node
    Node *temp = new Node(); 
    //Assign values to node
    temp->element = element;       
    temp->next = NULL;          

    if (isEmpty())
    {
        //if there is no front node make this the front node
        front = temp; 
    }
    else 
    {
        //else place node after rear 
        back->next = temp;
    }                  
    //set new rear
    back = temp;
}

void Queue::Dequeue()
{
    Node *temp = new Node;
    //Error checking
    if (isEmpty())
    {
        cout << "\nQueue is Emtpty\n";
    }
    else
    {
        //Set temp value to node being dequeued
        temp = front;
        //Set front to correct new node 
        front = front->next;
        //Dequeue node
        delete temp;
    }
}

string Queue::toString()
{
    Node *p = new Node;
    string result;
    string resultFinal;
    p = front;
    //Error Checking
    if (isEmpty())
    {
        cout << "\nNothing to Display\n";
    }
    //else add each node to result while the queue is not empty
    else
    {
        while (p != NULL)
        {
            result += "[" + p->element + "] -> ";
            p = p->next;
        }
        //Format result string
        resultFinal = result.substr(0, result.size() - 4);
    }
    return resultFinal;
}

int main()
{
    //Creating Queue
    Queue *q = new Queue();

    //Queueing things
    q->Enqueue("Turtle");
    q->Enqueue("Cat");
    q->Enqueue("Dog");
    q->Enqueue("Fish");
    

    //Printing queue
    cout << q->toString() << endl;
    //Dequeue one element
    q->Dequeue();

    cout << q->toString() << endl;
    //Delete queue
    delete q;

    return 0;
}