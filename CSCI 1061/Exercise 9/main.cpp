#include "vec3.h"

using namespace std;

class Person
{
    public:
        string _name;
        int _age;

        Person() {}
        Person(string name, int age)
        {
            _name = name;
            _age = age;
        }
        ~Person() {}

        friend ostream &operator<<(ostream &os, const Person &p)
        {
            cout << "(" << p._name << ", " << p._age << ")";
            return os;
        }

        const Person &operator=(const Person &p)
        {
            _name = p._name;
            _age = p._age;
            return *this;
        }

        const bool operator<(const Person &p)
        {
            if (_age < p._age)
            {
                return true;
            }
            return false;
        }

        const bool operator>(const Person &p)
        {
            if (_age < p._age)
            {
                return false;
            }
            return true;
        }
};

int main()
{
    vec3<int> v(1, 2, 3);
    v.print();
    cout << find_max(v) << endl;

    vec3<char> v2('z', 'y', 'x');
    v2.print();
    cout << find_max(v2) << endl;

    Person p1("Andrew", 19);
    Person p2("Tammy", 30);
    Person p3("Paul", 40);

    vec3<Person> v3(p1, p2, p3);
    v3.print();
    cout << find_max(v3) << endl;

    return 0;
}