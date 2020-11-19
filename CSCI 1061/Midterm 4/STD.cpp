#include <iostream>
#include <vector>

int main() 
{
    std::vector<int> v; 
    
    v.push_back(1); 
    v.push_back(2); 
    v.push_back(3);
    
    std::vector<int>::iterator i;
    for (i = v.begin(); i != v.end(); ++i) 
    {
        std::cout << *i << std::endl; 
    }
    return 0; 
}

#include <iostream> 
#include <list> 

using namespace std;

int main() 
{
    list<string> names;
    names.push_back("john");
    names.push_back("amanda");

    list<string>::reverse_iterator i;
    for (i = names.rbegin(); i != names.rend(); ++i) 
    {
        cout << *i << endl;
    }
    return 0; 
}

#include <map> 
#include <iostream> 
#include <string> 

using namespace std;

int main() 
{
    map<string, int> super_heros;
    super_heros["batman"] = 32;
    super_heros["wolverine"] = 137;
    super_heros["jean gray"] = 25;
    super_heros["superman"] = 35;

    map<string, int>::iterator i;
    for (i = super_heros.begin(); i != super_heros.end(); ++i) 
    {
        cout << "Age of " << i->first << " is " << i->second << endl;
    }

    return 0; 
}

// std::pair<string, int> ages;
// ages.first = "John"; // Key
// ages.second = 10;    // Value

#include <map> 
#include <iostream> 
#include <string> 

using namespace std;

int main() 
{
    map<string, int> super_heros;
    super_heros["batman"] = 32;
    super_heros["wolverine"] = 137;
    super_heros["jean gray"] = 25;
    super_heros["superman"] = 35;
  
    map<string, int>::iterator i = super_heros.find("batman"); 
    if (i != super_heros.end()) {
        cout << "Batman is " << i->second << endl;
    }

    i->second++;
    return 0; 
}