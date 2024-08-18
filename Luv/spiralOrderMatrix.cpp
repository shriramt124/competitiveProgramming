#include<iostream>
#include<vector>
using namespace std;
void spiraalMatrix(vector<vector<int>>v){
    int top = 0;
    int bottom = v.size()-1;
    int right = v[0].size()-1;
    int left = 0;
    //to track the direction 
    int direction  = 0;
    while(left<=right and top<=bottom){
          if(direction == 0){
            //print left to right 
            for(int row = left;row<=right;row++){
                cout<<v[top][row]<<" ";
            }cout<<endl;
            top++;//move downwards
          }else if(direction == 1){
            //moving top to bottom 
            for(int col = top;col<=bottom;col++){
                cout<<v[col][right]<<" ";
            }cout<<endl;
            right--;
             
          }else if(direction == 2){
            //right to left 
             for(int  row=right;row>=left;row--) {
                cout<<v[bottom][row]<<" ";
             }
             bottom--;

          }else if(direction == 3){
            //top to bottom 
            for(int i = bottom;i>=top;i--)
            { 
                cout << v[i][left] << " ";
            }cout<<endl;
            left++;
          }
          direction = (direction+1)%4;
    }
}
int main(int argc, char const *argv[])
{
    //n*m matrix 
    int n,m;cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>v[i][j];
        }
    }
    spiraalMatrix(v);
    return 0;
}
