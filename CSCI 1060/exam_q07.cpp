//Andrew Murdoch
//CSCI 1060U
//2018-12-11

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
  public:
    Stack();
    ~Stack();
    void push(int d);
    int pop();
    bool isEmpty() { return (top == NULL); };
    friend ostream &operator<<(ostream &os, Stack &s);

  private:
    Node *top;
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
    Node *newtop = new Node;
    newtop->data = d;
    newtop->next = top;
    top = newtop;
}

int Stack::pop()
{
    if (!isEmpty())
    {
        Node *temp = new Node;
        char value = top->data;
        temp = top;
        top = top->next;

        delete temp;
        return value;
    }
    else
    {
        cout << "ERROR: Stack is empty!\n";
        exit(1);
    }
}

ostream &operator<<(ostream &os, Stack &s)
{
    if (s.isEmpty())
    {
        cout << "<empty_stack>" << endl;
        return os;
    }
    if (!(s.isEmpty()))
    {
        Node *current = s.top;
        while (current != NULL)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
        return os;
    }
}

int main()
{
    Stack *s = new Stack();
    cout << *s << endl;
    s->push(5);
    cout << *s << endl;
    s->push(3);
    cout << *s << endl;
    while (!s->isEmpty())
    {
        cout << "Stack content popped: " << s->pop() << endl;
    }
    cout << *s << endl;
    delete s;
    return 0;
}