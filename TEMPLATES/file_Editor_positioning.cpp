#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <string>
#include<iomanip>

class SimpleFileEditor
{
    string filename;
    vector<string> lines;

public:
    SimpleFileEditor(const string fname)
    {
        this->filename = fname;
    }
    bool loadFile()
    {
        ifstream file;
        file.open(this->filename);
        if (!file.is_open())
        {
            cout << "Error in opening file " << endl;
            return false;
        }
        // if there are previous vector of lines then clear those
        lines.clear();
        string line;
        while (getline(file, line))
        {
            lines.push_back(line);
        }
        if (file.eof())
        {
            cout << "Loaded " << lines.size() << " lines from file" << endl;
        }
        file.close();
        return true;
    }
    bool saveFile()
    {
        fstream file;
        file.open(this->filename, ios::in | ios::out);
        if (!file.is_open())
        {
            cout << "error in opening file " << endl;
            return false;
        }
        for (auto &line : lines)
        {
            file << line << endl;
        }
        file.close();
        cout << "file saved successfully " << endl;
        return true;
    }

    void displayFile()
    {
        std::cout << "\n--- File Contents ---" << std::endl;
        for (size_t i = 0; i < lines.size(); ++i)
        {
            std::cout << std::setw(3) << (i + 1) << ": " << lines[i] << std::endl;
        }
        std::cout << "--- End of File ---\n"
                  << std::endl;
    }

    void insertLine(size_t position,const string &content){
         if(position > lines.size()){
             position = lines.size();//insert at the end file file point at the end 
         }
         lines.insert(lines.begin() + position, content);
         cout << "Lines inserted at poition" <<( position + 1 )<< endl;

    }
    void delPosition(size_t position){
        if(position < lines.size()){
            lines.erase(lines.begin() + position);
            cout << "Line " << (position + 1) << " Deleted" << endl;
        }else{
            cout << "Invalid line number" << endl;
        }
    }

    void modifyLinePosition(size_t position,const string&newcontent){
             if(position<lines.size()){
                 lines[position] = newcontent;
                 cout << "Line " << (position + 1) << " modified " << endl;
             }else{
                 cout << "Invalid line number " << endl;
             }
    }
};

int main(int argc, char const *argv[])
{
    SimpleFileEditor obj("position_test.txt");

    obj.loadFile();
    obj.displayFile();
    obj.insertLine(4, "this is sample inserted at 4 test");
    obj.displayFile();
    obj.modifyLinePosition(4,"this is modified line");
    obj.displayFile();
    obj.delPosition(4);
    obj.displayFile();

    return 0;
}
