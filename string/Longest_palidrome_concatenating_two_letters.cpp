#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<algorithm>

/*
https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/
You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.


Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".

*/
int longestPalindromicWord(vector<string>&words){
    //algorithm 
    //1.count the freq of each words
    //iterate over freq of each word 
    //reverse the each word and if it is not palindrome itself then 
    //take the minimum freq pair 
    //if palindrome then take the even pairs
    int length = 0;
    bool hasCentral = false;
    map<string, int> freq;
    for(auto ele:words)
        freq[ele]++;

        //2.
        for(auto ele:freq){
            string word = ele.first;
            int count = ele.second;
            string rev = word;
            reverse(rev.begin(), rev.end());
           if(word != rev){
            if(freq.find(rev )!= freq.end()){
                //take the minimum pairs
                int pairsCount = min(freq[rev], count);
                length = length + (pairsCount * 4);
                freq[word] -= pairsCount;
                freq[rev] -= pairsCount;
            }
           }else{
               int paircount = count / 2;
               length += (paircount * 4);
               freq[word] -= paircount * 2;
               if(freq[word] == 1)
                   hasCentral = true;
           }

        }
        if(hasCentral)
            length += 2;

        return length;
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the no of words you want to enter in the array " << endl;
    cin >> n;
    cout << "Enter the words " << endl;
    vector<string> words;
    for (int i = 0; i < n;i++){
        string str;
        cin >> str;
        words.push_back(str);
    }
    int ans  =  longestPalindromicWord(words);
    cout << "length of longest palindromic words is : " << ans << endl;

    return 0;
}
