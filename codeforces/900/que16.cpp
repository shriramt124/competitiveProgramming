#include <bits/stdc++.h>
using namespace std;

/* 
https://codeforces.com/problemset/problem/1666/D

Problem author: Dmitry Yakutov; problem developer: Roman Elizarov
This problem can be solved in a straightforward way. The key observation is that the order in which the
letters are called out does not matter in this game. We only need to know how many times each letter is
called out in order to go from the initial word s to the final word t.
So first, let us compute the number of occurrences of each letter from ‘A’ to ‘Z’ in both words s and t.
Let’s call them sa and ta for each letter a. Using these numbers, we can calculate how many times each
letter shall be called in order to get a chance of getting to t. That is sa − ta times for each letter a.
If sa − ta < 0 for any letter a, then the answer is “NO”.
Otherwise, there is a chance for a positive answer. However, we also need to verify that the order of
the letters in t is correct. The easy way to verify it is to simulate the game, dropping the first sa − ta
occurrences of each letter a, and then compare the result with t.


 */
void solv()
{
    string s, t;
    cin >> s >> t;
    map<char, int> m1;
    map<char, int> m2;
    for (auto ch : s)
    {
        m1[ch]++;
    }

    for (auto ch : t)
    {
        m2[ch]++;
    }

    if (s == t)
    {
        cout << "YES" << endl;
        return;
    }

    int i = 0;
    int j = 0;
    while (i < s.size() and j < t.size())
    {

        if (s[i] == t[j])
        {

            if (m1[s[i]] < m2[t[j]])
            {
                break;
            }

            if (m1[s[i]] == m2[t[j]])
            {
                m2[t[j]]--;
                j++;
            }
        }
        m1[s[i]]--;
        i++;
    }
    if (j == t.size())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solv();
    }
}