#include<iostream>
using namespace std;


 class Student{
    public:
        int id;
        string name;
        int age;
    
    Student *student;

    Student(int roll, string n, int a){
        this->id=roll;
        this->name =n;
        this->age= a ;
        this->student = NULL;
    }

 };

 void display (Student *student) {
    while (student != NULL)
    {
        /* code */
        cout << "Student with name "<< student->name << ", aged " << student->age << ", with roll number " << student->id <<endl;
        student = student->student;
    }
        
}

int main(){

        Student *s1 = new Student(10, "Gakwaya", 12);
        Student *s2= new  Student(19,"Igikeri", 23);
        Student *s3 =  new Student(20, "Trezor", 15);
        Student *s4=  new Student(29,"Bwenge", 28);
        Student *s5 = new Student(13, "Mwenewabo", 11);
       
        s1->student = s2;
        s2->student = s3;
        s3->student = s4;
        s4->student = s5;

        Student *head = s1;
        display(head);

}