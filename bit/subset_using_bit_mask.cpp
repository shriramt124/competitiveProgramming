 #include<iostream>
 #include<vector>
 using namespace std;
void solv(vector<int>arr,vector<vector<int>>&ans){
    int n = arr.size();
    int mask_ct = (1<<n);//2^n
    for(int mask = 0;mask<mask_ct;mask++){
        vector<int>subset;
        for(int i = 0;i<n;i++){
            if((mask & (1<<i))!=0){
                subset.push_back(arr[i]);
            }
        }
        ans.push_back(subset);
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>ans;
    solv(arr,ans);
    for(auto row:ans){
        for(auto ele:row){
            cout<<ele<<" ";
        }cout<<endl;
    }

    return 0;
}
