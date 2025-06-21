#include <fstream>
#include <iostream>
using namespace std;
#include <string>
#include<sstream>
#include <vector>

void funReadingStructuredData()
{
    fstream file("rama.txt", ios::app | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "error in opening file " << endl;
    }
    // file << "shriram tiwari" << endl;
    string firstname, lastname, age;
    int count = 1;
    while (file >> firstname >> lastname >> age)
    {
        cout << firstname << " " << lastname << " " << age << endl;
        if (file.bad())
        {
            cout << "\nError in reading file " << endl;
        }
    }

    if (file.eof())
    {
        cout << "\nSuccesfully Read the file " << endl;
    }

    file.close();
}

int main(int argc, char const *argv[])
{
    fstream file("rama.csv", ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "error in opening file " << endl;
    }
    file.seekg(0);
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string cell;
        while(getline(ss,cell,',')){//read the line untill it hits a comma and store it in cell 
            cout << cell << "\t";
        }
        cout << endl;
    }

    return 0;
}
