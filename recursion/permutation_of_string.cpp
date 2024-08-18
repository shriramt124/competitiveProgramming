#include <iostream>
using namespace std;
void permutation(string &str, int l, int r)
{
    if (l == r)
    {
        cout << str << " ";
    };

    for (int i = l; i < r; i++)
    {
        swap(str[i], str[l]);
        permutation(str, l + 1, r);
        swap(str[i], str[l]);
    }
}
void solv(string str)
{

    permutation(str, 0, str.length());
}
int main(int argc, char const *argv[])
{
    string str = "abc";
    solv(str);
    return 0;
}
