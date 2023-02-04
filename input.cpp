#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;

struct Child
{
    string name;
    int age;
    int rollNumber;
    float marks;
} s1, s2, s3, s4, s5;


bool validator(Child stud) 
{
    if ( stud.marks < 0  || stud.marks > 50 )
    {
        cout << endl
             << "RANGE IS 0 - 50" << endl;
        return false;
    }
    else if (stud.rollNumber < 0)
    {
        cout << endl
             << "ONLY +VE ALLOWED" << endl;
        return false;
    }
    else if ( stud.age < 10  || stud.age > 30)
    {
        cout << endl
             << "RANGE IS 0-30" << endl;
        return false;
    }
    else
    {
        return true;
    }
}

void print(Child s)
{
    cout << s.rollNumber << ", " << s.name << ", " << s.age << ", " << s.marks << endl;
}
int main()
{   int avg;
    int total;
    Child students[5] = {s1, s2, s3, s4, s5};

    cout << "====INSTRUCTIONS======" << endl;
    cout << "RANGE OF AGE  IS 0-30 " << endl;
    cout << "RANGE OF MARKS IN 0-50" << endl ;
    cout << "ONLY +VE ALLOWED FOR ROLL NUMBER" <<endl ;


    for (int i = 0; i < 5; i++)
    {
    start:
        cout << "Enter the data  for student " << i + 1 << endl;
        cout << "Roll Number:  ";
        cin >> students[i].rollNumber;
        cout << "Name:  ";
        cin >> students[i].name;
        cout << "Marks:  ";
        cin >> students[i].marks;
        cout << "Age:  ";
        cin >> students[i].age;

        if (!validator(students[i]))
        {
            goto start;
        }
        total += students[i].marks;
    }

    fstream dotText;
    dotText.open("tresor.txt", ios::out);

    for (int i = 0; i < 5; i++)
    {
        if (dotText.is_open())
        {
            dotText << students[i].rollNumber << ", " << students[i].name << ", " << students[i].age << ", " << students[i].marks << endl;
        }
    }
    avg = (total / 5);
    dotText.close();

    return 0;
}