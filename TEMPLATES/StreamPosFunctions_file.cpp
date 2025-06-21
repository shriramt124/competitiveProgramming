#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<vector>

class FilePosDemo{
    public:
    void demonstrateDemo(){
        createTestFile();//it will create test file
        fstream file("position_test.txt",ios::in | ios::out);//open for read and write
        if(!file.is_open()){
            cerr << "Error in opening file " << endl;
            return;
        }
        streampos initialpos = file.tellg();
        cout << "initial position " << initialpos << endl;
        //now read the data
        string line;
        getline(file, line);//it will read the first line
        cout << "Read : " << line << endl;
        cout << "Position after reading line : " << file.tellg() << endl;

        //seek to the beginning
        file.seekg(0, ios::beg);
        cout << "after seeking to begening " << file.tellg() << endl;

        //seek to end
        file.seekg(0, ios::end);
        cout << "After seeking from the end : " << file.tellg() << endl;

        //seek to relative to current position

        file.seekg(-20, ios::cur);
        cout << "After seeking -20 from current " << file.tellg() << endl;

        //read from new position

        getline(file, line);
        cout << "Read from new position " << line << endl;
        file.close();
    }

    private:
    void createTestFile(){
        ofstream file;
        file.open("position_test.txt");
        if(!file.is_open()){
            cerr << "Error in opening file" << endl;
        }
        for (int i = 1; i <= 10;i++){
            file << "Line " << i << ": this is test content for positioning" << endl;
        }
        file.close();

    }
};


int main(int argc, char const *argv[])
{
    FilePosDemo demo;
    demo.demonstrateDemo();

    return 0;
}
