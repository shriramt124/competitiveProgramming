#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    // ifstream fin;
    // fin.open("hello.txt");
    // cout << fin.tellg() << endl;
    // cout << (char)fin.get() << endl;
    // cout << fin.tellg() << endl;
    // fin.seekg(6);//it will shift the pointer from begening to pos 6 
    // cout << fin.tellg() << endl;//it will also shift to pos 6
    // cout << (char)fin.get() << endl;
  
    // fin.seekg(-2, ios_base::end);
    // cout << fin.tellg() << endl;

    ofstream fout;
    fout.open("hello.txt",ios::ate);
    

    return 0;
}
