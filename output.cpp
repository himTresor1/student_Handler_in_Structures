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
} stud1, stud2, stud3, stud4, stud5;

void mergeSort(Child arr[], int leftrNum, int righterNum)
{
	if (leftrNum < righterNum)
	{
		int mid = (leftrNum + righterNum) / 2;
		mergeSort(arr, leftrNum, mid );
		mergeSort(arr, mid + 1, righterNum);

		int n1 = mid - leftrNum + 1;
		int n2 = righterNum- mid;
		int l , i,  k;
		

		Child L[n1], R[n2];

		for (i = 0; i < n1; i++)
		{
			L[i] = arr[leftrNum + i];
		}
		for (l = 0; l < n2; l++)
		{
			R[l] = arr[mid + 1 + l];
		}

		i = 0;
		l = 0;
		k = leftrNum;
		while (i < n1 && l < n2)
		{
			if (L[i].marks <= R[l].marks)
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[l];
				l++;
			}
			k++;
		}

		while (i < n1)
		{
			arr[k] = L[i];
			i++;
			k++;
		}

		while (l < n2)
		{
			arr[k] = R[l];
			l++;
			k++;
		}
	}
}

Child getStudent(Child student, string line)
{
	int position = line.find(",");
	int rollNumber = stoi(line.substr(0, position));

	line = line.substr(position + 2);
	position = line.find(",");
	string name = line.substr(0, position);
	line = line.substr(position + 2);
	position = line.find(",");
	int age = stoi(line.substr(0, position));
	line = line.substr(position + 2);
	position = line.find(",");
	int marks = stoi(line.substr(0, position));
	student.rollNumber = rollNumber;
	student.name = name;
	student.age = age;
	student.marks = marks;
	return student;
} 

void print(Child stud, int index)
{
	cout << "RollNumber: " << stud.rollNumber << ",name: " << stud.name << ",Age:  " << stud.age << ",Marks: " << stud.marks << "out of 50" << endl;
}

int main()
{
	int totCount = 0;

	Child newStudents[5] = {stud1, stud2, stud3, stud4, stud5};

	fstream dotText;
	dotText.open("tresor.txt", ios::in);
	if (dotText.is_open())
	{
		string line;
		while (getline(dotText, line))
		{
			newStudents[totCount] =
				getStudent(newStudents[totCount], line);
			totCount++;
		}
	}
	dotText.close();

	mergeSort(newStudents, 0, 4);

	for (int i = 0; i < 5; i++)
	{
		print(newStudents[i], i + 1);
	}

	cout
		<< "The total number of students is: " << totCount << endl;
	return 0;
}