#include <iostream>
using namespace std;
#include "Student.cpp"

int main()
{ // Create objects statistically
    char name1[] = "abcd";
    char name2[] = "efgh";
    char name3[] = "ijkl";
    char name4[] = "mnop";

    student s1(20, name1, 100), s2(22, name2, 101), s3(24, name3, 102);
    // Create objects Dynmaically
    student *s6 = new student(26, name4, 103);

    // accessing class values

    student s7(s1); // default copy constructor always does shallow copy

    cout << "S1 age : " << s1.getAge() << endl;
    
    cout << "Total_students: " << student::total_students << endl;

    s1.display();
    s2.display();
    s3.display();
    s6->display();
    s7.display();

    return 0;
}