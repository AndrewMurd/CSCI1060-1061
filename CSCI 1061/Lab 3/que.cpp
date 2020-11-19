//que.cpp

#include "que.h"
#include "str.h"

que::que()
{
    front = NULL;
    back = NULL;
}

que::~que()
{
    while (!(front == NULL))
    {
        pop();
    }
}

char que::pop()
{
    Node *temp = new Node;
    _sz--;
    //Error checking
    if (front == NULL)
    {
        cout << "\nQueue is Emtpty\n";
    }
    else
    {
        //Set temp value to node being dequeued
        temp = front;
        cout << front->element;
        //Set front to correct new node
        del[_sz] = front->element;

        front = front->next;
        //Dequeue node
        delete temp;
    }
}

void que::push(char c)
{
    //Create temporary node
    Node *temp = new Node(); 
    //Assign values to node
    temp->element = c;       
    temp->next = NULL;
    _sz++;         

    if (front == NULL)
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

int que::size()
{
    return _sz;
}

int que::compress()
{
    delete [] del;
}