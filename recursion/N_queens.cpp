#include<iostream>
using namespace std;
#include<vector>

bool isSafe(int row,int col,vector<vector<int>>&v,int n){
        
        int x = row;
        int y = col;
        //check for the row 
        while(y>=0){
            if(v[x][y] == 1){
                return false;
            }
            y--;
        }

        //check for topleft diagonal 
        x = row ;
        y = col;
        while(x>=0 and y>=0){
            if(v[x][y] == 1){
                return false;
            }
            x--;
            y--;
        }
        //check for bottom diagonal 
        x = row ;
        y = col;
        while(x<n and y>=0){
            if(v[x][y] == 1){
                return false;
            }
            x++;
            y--;
        }

        return true;
}

void f(vector<vector<int>>&v,int col,int & count,int n){
    if(col == n){
     count++;
     return;
    }

    for(int row = 0;row<n;row++){
        if(isSafe(row,col,v,n)){
         v[row][col] = 1;
         f(v,col+1,count,n);
         v[row][col] = 0;
        }
    }
    
}
 int solv(int n){
    //create a 2d vector of size n*n 
   vector<vector<int>>v(n,vector<int>(n,0));
   
    int count = 0;
    f(v,0,count,n);
    return count;
 }
int main(int argc, char const *argv[])
{
    int n = 4;
    cout<<solv(n)<<endl;
    return 0;
}
