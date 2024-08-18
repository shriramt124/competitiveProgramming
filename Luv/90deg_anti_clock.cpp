#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>>&v){
    int n = v.size();
    //finding the transpose 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            swap(v[i][j],v[j][i]);
        }
    }
    //after swaping elements of each column 
    for(int col = 0;col<n;col++){
        int s = 0;
        int e = n-1;
        while(s<e){
            swap(v[s][col],v[e][col]);
            s++;
            e--;
        }
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>v[i][j];
        }
    }
   cout<<"Entered Matrix is : "<<endl;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }

   rotate(v);
    cout<<"rotating after anticlock wise 90deg is : "<<endl;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
