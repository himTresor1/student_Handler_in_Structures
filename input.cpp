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
             << "students marks should be between 0 and 50 " << endl;
        return false;
    }
    else if (stud.rollNumber < 0)
    {
        cout << endl
             << "Roll Number should be positive" << endl;
        return false;
    }
    else if ( stud.age < 10  || stud.age > 30)
    {
        cout << endl
             << "students age should be between 0 and 30" << endl;
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
{
    int total, average;
    string gameRules[] = { " Age should be between 10-30 ","marks must be between 0-50" , " The rollnumber should be a  positive number."};
    Child students[5] = {s1, s2, s3, s4, s5};

    cout << "====INSTRUCTIONS======" << endl;
    for (int i = 0; i < (end(gameRules) - begin(gameRules)); i++)
    {
        cout << "......." << gameRules[i] << endl;
    }


    for (int i = 0; i < 5; i++)
    {
    start:
        cout << "Enter the data  for student " << i + 1 << endl;
        cout << "Roll Number:  ";
        cin >> students[i].rollNumber;
        cout << "Name:  ";
        cin >> students[i].name;
        cout << "Age:  ";
        cin >> students[i].age;
        cout << "Marks:  ";
        cin >> students[i].marks;

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
    average = (total / 5);
    dotText.close();

    return 0;
}