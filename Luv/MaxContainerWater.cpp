#include<iostream>
using namespace std;
#include<vector>
int maxArea(vector<int>& height) {
        int n = height.size();//total length of height array 
        int sum  = 0 ;
        int ans = 0;
        int curr = 0;
        int next = curr+1;
        while(next < n and curr!=next){

            sum = min(height[curr],height[next])*(next-curr);
            ans = max(ans,sum);
            cout<<"sum : "<<sum<<endl;
            cout<<"ans : "<<ans<<endl;
            //check if next is greater than curr or not 
            if(sum<ans){
              curr++;
            }else{
                next++;
            }
        }
        return ans;
       
    }
int main(int argc, char const *argv[])
{
    vector<int>arr = {2,1,8,4,3,7,5};
    cout<<maxArea(arr);
    return 0;
}
