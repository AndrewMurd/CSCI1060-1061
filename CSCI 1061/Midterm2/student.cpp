#include <iostream>
#include <fstream>
#include "student.h"

using namespace std;

Student::Student(const string &name)
{
    _name = name;
}

Student::Student(const Student &o)
{
    _courses = o._courses;
    _name = o._name;
}

const Student &Student::operator=(const Student &o)
{
    _name = o._name;
    _courses = o._courses;
}

void Student::add_course(const string &course_code)
{
    Course a;
    a._code = course_code;
    _courses.push_back(a);
}

void Student::set_marks(const string &course_code, int marks)
{
    for (int i = 0; i < _courses.size(); i++)
    {
        if (course_code == _courses[i]._code)
        {
            _courses[i]._marks = marks;
        }
    }
}

int Student::get_marks(const string &course_code)
{
    for (int i = 0; i < _courses.size(); i++)
    {
        if (course_code == _courses[i]._code)
        {
            cout << _courses[i]._marks << endl;
        }
        else
        {
            cout << "Course does not exist!!!" << endl;
        } 
    }
}

ostream &operator<<(ostream &os, const Student &s)
{
    os << "Name: " << s._name << endl;
    os << "Courses: " << s._courses.size() << endl;
    for (int i = 0; i < s._courses.size(); i++)
    {
        os << s._courses[i]._code <<  " " << s._courses[i]._marks << endl;
    }
    return os;
}

istream &operator>>(istream &is, Student &s)
{
    
    return is;
}
