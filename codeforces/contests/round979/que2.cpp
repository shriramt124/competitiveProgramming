#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define khatam "\n"
#define bhago return


void solvByRam(){
    int n;
cin >> n;
    if(n == 1) {
        cout<<0<<khatam;
        bhago;
    }
    else{
        for(int i = 0;i<n-1;i++){
            cout<<0;
        }
        cout<<1<<khatam;
    }
    bhago;

}

int main() {
  int t;
  cin >> t;
  while (t--) {
     solvByRam();
    
  }
  return 0;
}