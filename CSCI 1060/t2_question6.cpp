//Andrew Murdoch
//CSCI 1060U
//2018-11-30

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
  public:
    Stack();             //constructor
    ~Stack();            //destructor
    void push(int d);    //pushes node onto top of stack
    int pop();           //pops top node off of stack -- returns integer popped
    bool isEmpty();      //checks if stack is empty
    void displayStack(); //display contents of stack
                         //from top to bottom
  private:
    Node *top; //points to top node in stack
};

Stack::Stack()
{
    top = NULL;
}

Stack::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

void Stack::push(int d)
{
    Node *temp = new Node;
    temp->data = d;
    temp->next = top;
    top = temp;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "ERROR: you can't pop from empty stack!\n";
        exit(1);
    }
    else
    {
        Node *temp = new Node;
        int value = top->data;
        //temp = top;
        top = top->next;

        delete temp;
        return value;
    }
}

bool Stack::isEmpty()
{
    return (top == NULL);
}

void Stack::displayStack()
{
    cout << "<top>" << endl;
    Node *current = top;
    while (current != NULL)
    {
        cout << current->data << endl;
        current = current->next;
    }
    cout << "<bottom>" << endl << endl;
}

int main()
{
    Stack s; //= new Stack(); //don't need "new" for ordinary variables!
    s.displayStack();
    s.push(20);
    s.push(30);
    s.displayStack();
    s.push(40);
    s.push(12);
    s.displayStack();
    s.pop();
    s.displayStack();
    s.pop();
    s.displayStack();
    s.pop();

    return 0;
}