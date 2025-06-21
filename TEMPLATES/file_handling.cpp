#include<fstream>
#include<iostream>
using namespace std;

void tellgfun(){
    ifstream fin;
    int pos;
    fin.open("./hello.txt",ios::app);
    pos = fin.tellg();//initially pointer points to the first pos
    cout << pos << endl;
    char ch;
    fin >> ch;//the first character will read and then the pointer will move to the next pos
    pos = fin.tellg();
    cout << pos << endl;

    ofstream fout;
    fout.open("hello.txt", ios::app);
    int pos1;
    pos1 = fout.tellp();
    cout << pos1 << endl;
    fout << "shriram tiwari" << endl;
    pos1 = fout.tellp();
    cout << pos1 << endl;
}

int main(int argc, char const *argv[])
{
    // ofstream fout;
    // fout.open("./hello.txt",ios::out);
    // fout << "Hello world";
    // // fout.close();
    // ifstream fin;
    // char ch;
    // fin.open("./hello.txt",ios::in);
    // ch = fin.get();
    // while(!fin.eof()){
    //     cout << ch;
    //     ch = fin.get();
    // }

    tellgfun();

    return 0;
}
