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

void mergeSort(Child arr[], int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);

		int i, j, k;
		int n1 = middle - left + 1;
		int n2 = right- middle;

		Child L[n1], R[n2];

		for (i = 0; i < n1; i++)
		{
			L[i] = arr[left + i];
		}
		for (j = 0; j < n2; j++)
		{
			R[j] = arr[middle + 1 + j];
		}

		i = 0;
		j = 0;
		k = left;
		while (i < n1 && j < n2)
		{
			if (L[i].marks <= R[j].marks)
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		while (i < n1)
		{
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2)
		{
			arr[k] = R[j];
			j++;
			k++;
		}
	}
}

Child getStudent(Child student, string line)
{
	int pos = line.find(",");
	int rollNumber = stoi(line.substr(0, pos));
	line = line.substr(pos + 2);
	pos = line.find(",");
	string name = line.substr(0, pos);
	line = line.substr(pos + 2);
	pos = line.find(",");
	int age = stoi(line.substr(0, pos));
	line = line.substr(pos + 2);
	pos = line.find(",");
	int marks = stoi(line.substr(0, pos));
	student.rollNumber = rollNumber;
	student.name = name;
	student.age = age;
	student.marks = marks;
	return student;
} 

void print(Child stud, int index)
{
	cout << "RollNumber: " << stud.rollNumber << ",name: " << stud.name << ",Age:  " << stud.age << ",Marks: " << stud.marks << "/50" << endl;
}

int main()
{
	int totCount = 0;

	Child newStudents[5] = {stud1, stud2, stud3, stud4, stud5};

	fstream myFile;
	myFile.open("tresor.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			newStudents[totCount] =
				getStudent(newStudents[totCount], line);
			totCount++;
		}
	}
	myFile.close();

	mergeSort(newStudents, 0, 4);

	for (int i = 0; i < 5; i++)
	{
		print(newStudents[i], i + 1);
	}

	cout
		<< "The total number of students is: " << totCount << endl;
	return 0;
}