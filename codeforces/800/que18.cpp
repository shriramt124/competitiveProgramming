#include <iostream>
using namespace std;
#include <vector>
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        if(k == 1 and x == 1) cout<<"NO"<<endl;
        else if(x>1 and k>1){
            cout<<"YES"<<endl;
            cout<<n<<endl;
            for(int i = 0;i<n;i++){
                cout<<1<<" ";
            }cout<<endl;
        }else if(x == 1 and k == 2){
            if(n%2 == 0){
                cout<<"YES"<<endl;
                int size = n/2;
                cout<<size<<endl;
                for(int i  = 0;i<size;i++){
                    cout<<2<<" ";
                }cout<<endl;

            }else cout<<"NO"<<endl;
        }
        else if(x == 1 and k >2){
            cout<<"YES"<<endl;
            if(n%2 == 0){
                int twosize = n/2;
                cout<<twosize<<endl;
                for(int i = 0;i<twosize;i++){
                    cout<<2<<" ";
                }cout<<endl;
            }else{
                int twosize = n/2-1;
                int threesize = 1;
                cout<<twosize+threesize<<endl;
                for(int i = 0;i<twosize;i++){
                    cout<<2<<" ";
                }cout<<3<<endl;
            }
            
        }
    }
    return 0;
}
