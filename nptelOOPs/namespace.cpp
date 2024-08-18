#include<iostream>
using namespace std;
int var = 0;
namespace Test{
    int var = 2;
}

int main(int argc, char const *argv[])
{
    using namespace Test;
    int var = 1;
    {
        cout<<::var<<var<<Test::var<<endl;
    }
    
    return 0;
}
