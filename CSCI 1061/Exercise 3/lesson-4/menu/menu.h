#ifndef __menu_h__
#define __menu_h__

#include <string>

void add_menu_item(std::string label, void (*cb)());
void run_menu_loop();
void clear_menu_items();

#endif
