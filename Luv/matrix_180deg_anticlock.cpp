#include<iostream>
#include<vector>
using namespace std;

/* 
   1  2   3
   4   5  6
   7   8  9

   //first swaping elements column wise 
    
   3   2   1 
   6   5   4
   9   8   7

   //now reversing each column 

    9   8  7
    6   5  4
    3   2  1



 */
  void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        //swapping each element of column
        for(int row = 0;row<n;row++){
            int s = 0;int e = n-1;
            while(s<e){
                swap(matrix[row][s],matrix[row][e]);
                s++;
                e--;
            }
        }
        //now reversing each colmum 
        for(int col = 0;col<n;col++){
            int s = 0;
            int e = n-1;
            while(s<e){
                swap(matrix[s][col],matrix[e][col]);
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
cout<<"matrix after rotating 180 def anticlock wise is : "<<endl;
 for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}

