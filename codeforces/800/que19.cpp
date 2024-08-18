#include <iostream>
using namespace std;
#include <vector>
/* 
First, let's make the sum of the array elements ≥0
. To do this, we just need to change some −1
 to 1
. The number of such replacements can be calculated using a formula or explicitly simulated.

After that, there are two possible situations: either the product of all elements is equal to 1
, or the product of all elements is equal to −1
. In the first case, we don't need to do anything else. In the second case, we need to replace one more −1
 with 1
 (note that in this case the sum will remain ≥0
).
 */

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
           int sum = 0;
           int neg = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum+=arr[i];
            arr[i]<0 ? neg++:neg+=0;

        }
        if(sum>=0 and neg%2 == 0){
            cout<<0<<endl;
        }else if(sum>=0 and neg%2!=0){
            cout<<1<<endl;
        }
        else if(sum<0){
            //first make the sum as positive
            int operation;
             if(abs(sum)%2 == 0){
                operation = abs(sum)/2;
             }
             else
             operation = abs(sum)/2+1;
              
             neg = neg-operation;//agar iske baad neg odd hai to product -1 aayega hi 
             if(neg%2 != 0)  operation++;
             cout<<operation<<endl;
        }

    }
    return 0;
}
