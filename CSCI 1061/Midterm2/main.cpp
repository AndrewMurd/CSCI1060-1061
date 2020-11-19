#include "iostream"
#include "fstream"
#include "student.h"

using namespace std;

int main()
{
    cout << "Setting up John" << endl;

    Student a("John");

    a.add_course("csci1061");
    a.add_course("csci1060");

    a.set_marks("csci1061", 95);
    a.set_marks("csci1060", 93);

    cout << "Setting up Samantha" << endl;

    Student b("Samantha");

    b.add_course("csci4220");
    b.add_course("csci3050");

    b.set_marks("csci4220", 91);
    b.set_marks("csci3050", 92);

    cout << "==========================================================" << endl;
    cout << "Printing John's info" << endl;
    cout << a << endl;

    cout << "==========================================================" << endl;
    cout << "Printing Samantha's info" << endl;
    cout << b << endl;

    cout << "==========================================================" << endl;
    cout << "Updating Samantha's marks for csci4210" << endl;
    b.set_marks("csci4210", 94);

    cout << "==========================================================" << endl;
    cout << "Getting Samantha's marks for csci6000" << endl;
    cout << b.get_marks("csci6000") << endl;

    cout << "==========================================================" << endl;
    cout << "Getting Samantha's marks for csci3050" << endl;
    cout << b.get_marks("csci3050") << endl;

    cout << "==========================================================" << endl;
    cout << "Updating Samantha's marks for csci4220" << endl;
    b.set_marks("csci4220", 100);

    cout << "==========================================================" << endl;
    cout << "Printing Samanthas's info after updating her marks." << endl;
    cout << b << endl;

    cout << "==========================================================" << endl;
    cout << "Saving John and Samantha's info to a file." << endl;
    ofstream f1("students.txt");
    f1 << a << endl
       << b << endl;
    f1.close();
    cout << "Done" << endl;

    cout << "==========================================================" << endl;
    cout << "Loading John and Samantha's info to a file." << endl;
    ifstream f2("students.txt");
    Student c, d;
    f2 >> c >> d;
    cout << "Done" << endl;

    cout << "==========================================================" << endl;
    cout << "Printing John's info" << endl;
    cout << a << endl;

    cout << "==========================================================" << endl;
    cout << "Printing Samantha's info" << endl;
    cout << b << endl;

    return 0;
}