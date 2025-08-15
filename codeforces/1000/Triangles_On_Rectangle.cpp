#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/1620/B

/* 
Solution : 
The area of a triangle is equal to its base multiplied by its height divided by 2
. Let the two points that have to be on the same side of a rectangle form its base. To maximize it, let's choose such two points that are the most apart from each other — the first and the last in the list.

Then the height will be determined by the distance from that side to the remaining point. Since there are points on all sides, the points on the opposite side are the furthest. Thus, the height is always one of h
 or w
, depending on whether we picked the horizontal or the vertical side.

So we have to check four options to pick the side and choose the best answer among them.
*/
int main(){
    int t;
    cin>>t;
    while(t--){
        long long w,h;
        cin>>w>>h;
        long long ans = INT_MIN;
        for(int i = 0;i<4;i++){
        long long k;
        cin>>k;
        long long first,last;
        vector<long long>temp;
        for(int j = 0;j<k;j++){
            long long x;
            cin>>x;
            temp.push_back(x);
        }
        first = temp[0];
        last = temp.back();
        long long width = last-first;
        long long height;
        if(i<=1){
            height = h;

        }else height = w;
        ans = max(ans,width*1LL*height);

        }
        cout<<ans<<endl;
    }
}