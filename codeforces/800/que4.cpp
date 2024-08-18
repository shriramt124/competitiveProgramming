#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (n % 3 == 0)
            cout << "Second" << endl;

        else
        {
            cout << "First" << endl;
        }
    }
    return 0;
}
