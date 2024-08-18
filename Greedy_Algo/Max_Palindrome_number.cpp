#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// making the largest palindrome by rearranging the string
//similar leetcode question is --> https://leetcode.com/problems/largest-palindromic-number/


string LargestPalindrome(string str)
{
    vector<int> freq(10, 0);
    for (int i = 0; i < str.length(); i++)
    {
        freq[str[i] - '0']++;
    }
    // from 9-> 0 count the freq and add it to the answer string
    // we also have to put the mid elemment of odd frequency or frequence = 1
    bool isFoundMid = false;
    char mid;
    string ans;
    for (int i = 9; i >= 0; i--)
    {
        if (i == 0 && ans.empty())
            break;

        // we have to take just even characher for both left and right side
        while (freq[i] > 1)
        {
            ans += to_string(i);
            freq[i] -= 2;
        }
        if (freq[i] == 1 and !isFoundMid)
        {
            mid = (i);
            isFoundMid = true;
        }
    }
    // we have taken the left side part of the string now
    string temp = ans;
    reverse(temp.begin(), temp.end());
    if (isFoundMid == true)
    {
        ans += to_string(mid);
    }
    ans += temp;
    return ans;
}

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    string ans = LargestPalindrome(str);
    cout<<"largest palindrome  formed by "<<str<<" is "<<ans<<endl;

    return 0;
}