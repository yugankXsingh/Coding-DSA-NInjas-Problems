#include <string.h>
#include <iostream>
using namespace std;

class student
{
private:
    char *name;

public:
    int roll_no;
    int age;
    static int total_students; // static properties belong to a class and not to individual objects

    student(int age, char *name, int roll_no)
    {
        this->age = age;
        this->roll_no = roll_no;

        // shallow copy
        //  this->name = name;

        // DEEP COPY
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        // increasing the total_students
        total_students++;
    }

    // Copy Constructor
    student(student const &s)
    {
        this->age = s.age;
        this->roll_no = s.roll_no;
        // this->name = s.name // shallow copy

        // Deep Copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);

        // increasing the total_students
        total_students++;
    }

    void display()
    {
        cout << "Name: " << name << " Age: " << age << " Roll_no: " << roll_no << endl;
    }
    int getAge()
    {
        return age;
    }
    int get_roll_no()
    {
        return roll_no;
    }
};

// initializing static data members
int student::total_students = 0;