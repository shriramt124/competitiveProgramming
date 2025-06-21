#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void Basic_Text_writing(){
    ofstream fout;
    fout.open("./example.txt");
    if (!fout.is_open())
    {
        cout << "error in opening file" << endl;
        return ;
    }
    fout << "Hello,world" << endl;
    fout << "Number : " << 42 << endl;
    fout << "PI : " << 3.14159 << endl;
    string name = "Shriram";
    fout << "Name : " << name << endl;
    fout.close();
    cout << "file has written successfullly" << endl;
}

void Writing_User_Input(){
    ofstream file;
    file.open("./userdata.txt");
    if(!file.is_open()){
        cout << "Error in openeing file " << endl;
        return;
    }
    string name, hobby;
    int age;
    cout << "Enter your name " << endl;
    // cin >> name;
    getline(cin, name);
    cout << "Enter your hobby " << endl;
    //cin >> hobby;
    getline(cin, hobby);
    cout << "Enter your age " << endl;
    cin >> age;
    cin.ignore();//clear the newline character
    //write to the file

    file << "Name : " << name<<endl;
    file << "Age : " << age << endl;
    file << "Hobby :" << hobby << endl;
    file.close();

    cout << "Data saved to the file " << endl;
}

void Basic_Text_Reading(){
    ifstream file;
    file.open("example.txt");
    if(!file.is_open()){
        cout << "Error in opening file " << endl;
        return;
    }
    string line;
    cout << "Enter file contents " << endl;
    getline(cin, line);

    while(getline(file,line)){//it will read line by line 
        cout << line << endl;

    }
    file.close();
    return;
}

void Read_structured_data(){
    ofstream file;
    file.open("./structured_data.txt");

    if (!file.is_open())
    {
        cout << "error in oepning file " << endl;
        return;
    }
    file << "shriram 22 Engineer" << endl;
    file << "Arjun 30 Teacher" << endl;
    file << "Charlie 28 Doctor" << endl;
    file.close();
 
    ifstream infile;
    infile.open("./structured_data.txt");
    if(!infile.is_open()){
        cout << "error in opening ifle " << endl;
        return;
    }
    string name, profession;
    int age;
    cout << "structured data is : " << endl;
    while(infile >> name >> age >> profession){
        cout << "Name: " << name
                  << ", Age: " << age
                  << ", Profession: " << profession <<  endl;
    }
    infile.close();
}

void Read_character_by_character(){
    ifstream infile;
    infile.open("example.txt");
    if(!infile.is_open()){
        cout << "Error in opening file " << endl;
        return;
    }
    char ch;
    cout << "File contents " << endl;
    while(infile.get(ch)){
        cout << ch;
    }
    cout << endl;
    infile.close();
}

void file_pos_seeking(){
    fstream file("example.txt", ios::in | ios::out);
    if(!file.is_open()){
        cout << "Error in opening file " << endl;
        return;
    }
    int pos = file.tellg();
    cout << pos << endl;

    //move to the begning
    file.seekg(0, ios::beg);

    //move to the end

    file.seekg(0, ios::end);
    pos = file.tellg();
    cout << "End pos is : " << pos << endl;

    //move 10 characters from begining
    file.seekg(10, ios::beg);
    pos = file.tellg();
    cout << "10 char from begening is : " << pos << endl;
    
    file.close();

     
    return;
}

void ErrorHandling(){
    ifstream file;
    file.open("example.txt");
    if(!file.is_open()){
        cout << "error in opening file " << endl;
        return;
    }

    string line;
    int lineNumber = 1;
    while(getline(file,line)){
        cout << "Line " << lineNumber << line << endl;

        lineNumber++;
        //check for bad errors
         if(file.bad()){
             cerr << "Fatal Error occured while reading file " << endl;
             break;
         }
    }

    //check why loop ended 

    if(file.eof()){
        cout << "Successfully Read Entire file " << endl;
    }else if(file.fail()){
        cout << "Read operation failed " << endl;
    }
    file.close();
    return;
}

 
int main(){

    //Writing_User_Input();
    //Basic_Text_Reading();
    //Read_structured_data();
   // Read_character_by_character();
    //file_pos_seeking();
    ErrorHandling();
    return 0;
}