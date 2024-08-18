#include<iostream>
 
using namespace std;
#include<vector>
int solv(vector<int>arr,int b){
    int n = arr.size();
    int maxi = INT8_MIN;
    int sum = 0;
    for(int i = 0;i<b;i++){
       sum+=arr[i];
    }
    maxi = sum;
    int r = arr.size()-1;
    for(int i = b-1;i>=0;i--){
        sum+=arr[r];
        r--;
        sum-=arr[i];
        maxi   = max(sum,maxi);
    }
 return maxi;

}
int main(int argc, char const *argv[])
{
    vector<int>arr = { -533, -666, -500, 169, 724, 478, 358, -38, -536, 705, -855, 281, -173, 961, -509, -5, 942, -173, 436, -609, -396, 902, -847, -708, -618, 421, -284, 718, 895, 447, 726, -229, 538, 869, 912, 667, -701, 35, 894, -297, 811, 322, -667, 673, -336, 141, 711, -747, -132, 547, 644, -338, -243, -963, -141, -277, 741, 529, -222, -684, 35 };
    int b = 48;
    int res = solv(arr,b);
    cout<<res<<endl;
    return 0;
}
