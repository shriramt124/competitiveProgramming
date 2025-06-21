#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>

class Student{
    public:
    string name;
    int id;
    double grade;
};

bool saveStudents(const vector<Student>&students,const string &filename){
    ofstream file(filename);
    if(!file.is_open()){
        cerr << "Error:cannot create file " << filename << endl;
        return false;
    }
    for(const auto &student:students){
        file << student.name << " " << student.id << " " << student.grade << endl;
    }

    file.close();
    return true;
}

bool loadStudents(vector<Student>&students,const string &filename){
    ifstream file;
    file.open(filename);
    if(!file.is_open()){
        cerr << "Can not open file " << filename << endl;
        return false;
    }
    students.clear();//first clear the previos studetns vector
    Student student;
    while(file >>student.name>>student.id>>student.grade){
        students.push_back(student);
    }
    if(file.bad()){
        cout << "Error:Problem in reading file " << endl;
        return false;
    }
    file.close();
    return true;
}
void displayStudents(const vector<Student>&students){
    std::cout << std::setw(15) << "Name"
              << std::setw(8) << "ID"
              << std::setw(8) << "Grade" << std::endl;
    std::cout << std::string(31, '-') << std::endl;

    for (const auto &student : students)
    {
        std::cout << std::setw(15) << student.name
                  << std::setw(8) << student.id
                  << std::setw(8) << std::fixed << std::setprecision(2) << student.grade << std::endl;
    }
}

int main()
{
    vector<Student> students = {
        {"Alice", 101, 85.5},
        {"Bob", 102, 92.0},
        {"Charlie", 103, 78.5},
        {"Diana", 104, 96.0}};


        //save students to a file 
        if(saveStudents(students,"students.txt")){
            cout << "students saved successfully" << endl;
        }
        


        //clear the vector and reload the file
        students.clear();
        if(loadStudents(students,"students.txt")){
            cout << "Students loaded successfully" << endl;
            cout << "\n student Data" << endl;
            displayStudents(students);
        }


        //load students from file 


    return 0;
}