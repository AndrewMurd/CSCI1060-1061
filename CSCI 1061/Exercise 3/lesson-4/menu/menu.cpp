#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct menu
{
  string label;
  void (*cb)();
};

std::vector<menu*> menu_items;

void add_menu_item(string label, void (*cb)())
{
  menu* item = new menu;
  item->label = label;
  item->cb = cb;
  menu_items.push_back(item);
}

void clear_menu_items()
{
  for (int i=0; i<menu_items.size(); ++i) {
    delete menu_items[i];
  }
  menu_items.clear();
}

void print_menu_items()
{
  for (int i=0; i<menu_items.size(); ++i) {
    cout << "[" << i << "] " << menu_items[i]->label << endl;
  }
}

void run_menu_loop()
{
  union choice {
    char c;
    int i;
  };
  choice c;

  do {
    print_menu_items();
  
    cout << "Enter your choice (q to quit): ";
    cin >> c.c;
    if (c.c == 'q') break;
    cin.putback(c.c);

    cin >> c.i;
    if (c.i >= 0 && c.i < menu_items.size()) {
      menu_items[c.i]->cb();
    }
    else {
      cout << "Invalid choice." << endl;
    }
      
    
  } while(true);
}


