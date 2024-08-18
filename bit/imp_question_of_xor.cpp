#include<iostream>
using namespace std;
/* 
given an array of n integers all integers are present in even count except one 
find that one integer which has odd count in O(N) time complexity and O(1) space 
 */
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    /* 
    let arr = 1 2 1 3 3 4 4
    if we perform xor then the numbers which are even will canclled out 
    and at the end only that number will present which is odd 
    property used is : x^x = 0 and x^0 = 0
    
     */
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans^=arr[i];
    }
    cout<<ans<<endl;
    return 0;
}
