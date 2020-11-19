#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std;

int main() 
{
    std::vector<int> v;
    for (int i=0; i<10; ++i) v.push_back(i*2);

    std::for_each(v.begin(), v.end(), [](int val){ cout << val << endl; });
    
    return 0; 
}