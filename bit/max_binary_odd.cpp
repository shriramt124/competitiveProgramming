#include<iostream>
using namespace std;
#include<vector>
 string maximumOddBinaryNumber(string s) {
        int length = s.length();
        int countone = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i] == '1') countone++;
        }
        vector<int>v(length,0);
         v[length-1] = 1;
         countone--;
         if(countone>0){
             int k = 0;
             while(countone--){
                 v[k++] = 1;
             }
         }
         string ans="";
         for(int i =0;i<length;i++){
              string ele = to_string(v[i]);
              ans += ele;
         }
         return ans;



    }
int main(int argc, char const *argv[])
{
    string str = "01011";
    string ans =  maximumOddBinaryNumber(str);
    cout<<ans<<endl;
    return 0;
}
