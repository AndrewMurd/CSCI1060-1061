#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
  double d, t;

  try {  
    cout << "Enter distance: ";
    cin >> d;
    cout << "Enter time: ";
    cin >> t;

    if (t <= 0) throw d;

    cout << "Velocity is: " << d/t << endl; 
  }
  catch (double e)
  {
    cout << "Exception raised." << endl;
  }
  cout << "Continue ..." << endl;

  return 0;
}

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class BadTime
{
  private:
  double t;
  string n;

  public:
  BadTime(double time) : t(time) {
    n = "BadTime";
  }

  string getName() const { return n; }
  double getValue() const { return t; }
};

int main()
{
  double d, t;

  try {  
    cout << "Enter distance: ";
    cin >> d;
    cout << "Enter time: ";
    cin >> t;

    if (t <= 0) throw BadTime(t);

    cout << "Velocity is: " << d/t << endl; 
  }
  catch (BadTime bd)
  {
    cout << "Exception " << bd.getName()
         << " called with value " << bd.getValue()
         << endl;
  }
  
  cout << "Continue doing what you were doing." << endl;
  
  return 0;
}

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class BadTime
{
  private:
  double t;
  string n;

  public:
  BadTime(double time) : t(time) {
    n = "BadTime";
  }

  string getName() const { return n; }
  double getValue() const { return t; }
};

class ZeroDistance
{};

class NegativeDistance
{};

int main()
{
  double d, t;

  try {  
    cout << "Enter distance: ";
    cin >> d;
    if (d == 0) throw ZeroDistance();
    if (d < 0) throw NegativeDistance();
    
    cout << "Enter time: ";
    cin >> t;
    if (t <= 0) throw BadTime(t);
    

    cout << "Velocity is: " << d/t << endl; 
  }
  catch (BadTime bt)
  {
    // We explictly name the catch paramter bd, since we plan to use
    // it below
    
    cout << "Exception " << bt.getName()
         << " called with value " << bt.getValue()
         << endl;
  }
  catch (ZeroDistance)
  {
    // Note we do not mention (name) catch parameter.
    // Since we don't plan to use it here.

    cout << "Exception: ZeroDistance." << endl;
  }
  catch (...)
  {
    // A catch-all block
    //
    // Notice that the try-block is throwning a NegativeDistance
    // exception that we don't explicitly catch.  We
    // use this catch-all block to catch any unhandled
    // exceptions that may be thrown by the try block.

    cout << "Exception: an unhandled exception." << endl;
  }

  cout << "Program safely continues, once the exception is handeled." << endl;

  return 0;
}

// double safeDivide(int top, int bottom) throw (DivideByZero)
// {
//     if (bottom == 0)
//        throw DivideByZero( );

//     return top/static_cast<double>(bottom);
// }