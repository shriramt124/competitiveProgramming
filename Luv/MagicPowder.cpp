#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int a[n];
    int b[n];
    for(int i = 0;i<n;i++){
      cin>>a[i];
    }
    for(int i = 0;i<n;i++){
        cin>>b[i];
    }
    int ans = 0;
    bool isRunning = true;
    int count = 0;
    int magicPowder = k;
    while(isRunning){
         for(int i = 0;i<n;i++){
             bool isRun = false;//is scene me chala ki nahi chala
            if((b[i]-a[i])>=0){
                b[i] = b[i]-a[i];
                isRun = true;
            }else if((b[i]+1 - a[i])>=0 && magicPowder >=1){
                 b[i] = b[i]-a[i]+1;
                 magicPowder--;
                 isRun = true;
            }
            if(!isRun){//means  chala hi hai
               isRunning = false;
               ans = count;
               break;
            }else{
                 if(i == n-1 and isRun){
                    count++;
                 }
            }
         }
    }

    cout<<ans<<endl;;

    return 0;
}
