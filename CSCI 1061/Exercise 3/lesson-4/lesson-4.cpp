#include <iostream>
#include "menu.h"

using namespace std;

void add()
{
  int n1, n2;
  
  cout << "== add == " << endl;
  cout << "enter 1st number: "; cin >> n1;
  cout << "enter 2nd number: "; cin >> n2;
  cout << "result = " << n1 + n2 << endl;
}

void sub()
{
  int n1, n2;
  
  cout << "== sub == " << endl;
  cout << "enter 1st number: "; cin >> n1;
  cout << "enter 2nd number: "; cin >> n2;
  cout << "result = " << n1 - n2 << endl;
}


void square()
{
  int n;
  cout << "== square == " << endl;
  cout << "enter number: ";
  cin >> n;
  cout << "result = " << n*n << endl;
}

int main()
{
  add_menu_item("add", add);
  add_menu_item("square", square);
  add_menu_item("sub", sub);
  run_menu_loop();
  clear_menu_items();
  
  return 0;
}
