#include <bits/stdc++.h>
using namespace std;


struct Student {
    public:
        Student *head;
        int id;
        string name;
        int marks;
        Student* next;
        Student(int id, string name, int marks ){
            this->id=id;
            this->name = name;
            this->marks= marks;
        }
        
};
 void display(Student *student){
    while( student !=NULL){
        cout << "Student with name" << student->name << " , and id" << student->id << ", has marks  " << student->marks << "out of /50." << endl;
        cout<<endl;
        student= student->next;

    }
 }
void  lengthcounter(Student *student){
    int count;
    while (student != NULL)

    {
        count++;
        Student.next= next;
    }

}
  int main(){


    //Static assignment
        Student s1(1, "Amizero Tresor",23);
        Student s2(2, "Joy Kevin", 24);
        Student s3(3,"Himself Arnold", 45);

    //Dynamic assignment

        Student *s4= new Student(4,"Hiddsdfsdf", 34);
        Student *s5 = new Student(5, "asdkjfbad", 45);


        Student *head= &s1; 
        s1.next=&s2;
        s2.next= &s3;
        // s3.next= &s4;


            display(&s1);

         }