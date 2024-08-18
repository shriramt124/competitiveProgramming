#include<iostream>
using namespace std;
#include<vector>
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

    //transpose --then revrese each row 
    for(int i = 0;i<n;i++){
        for(int j = 0 ;j<i;j++){
            swap(v[i][j],v[j][i]);
        }
    }
    //reverse each row 
    cout<<"transpose matrix is : "<<endl;
 for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
 //reverse each row 
 for(int i = 0;i<n;++i){
    int s = 0;
    int e = v[i].size()-1;
    while(s<e){
        swap(v[i][s],v[i][e]);
        s++;
        e--;
    }

 }

 cout<<"90 deg of matrix is : "<<endl;
  for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}
