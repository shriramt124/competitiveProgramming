#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Item{
    public:
    int value;
    int weight;
};
static bool cmp(Item i1 ,Item i2){

    double r1 = static_cast<double>(i1.value)/i1.weight;
    double r2 = static_cast<double>(i2.value)/i2.weight;
    return r1 > r2;
}
double fractionalKnapstack(int w,vector<Item>&items){
    //! Time:O(nlogn)
    //space --> O(sorting)
      double ans = 0;
      sort(items.begin(),items.end(),cmp);
      
      for(const auto &item:items){
         if(item.weight<=w){
            //we can pick the complete item
            ans+=item.value;
            w-=item.weight;
         }else{
            //we can not pick the complete item and space is left so we will use fraction of that item
            double fraction = static_cast<double>(w)/item.weight;
               ans = ans + fraction*item.value;
               w = 0;
         }
      }
      return ans;

}
int main()
{
    int n,w;
    cin>>n>>w;
    vector<Item>items;
    for(int i = 0;i<n;i++){
        int v,w;
        cin>>v>>w;
        Item it;
        it.value = v;
        it.weight = w;
        items.push_back(it);
        
    }
    cout<<fractionalKnapstack(w,items)<<endl;

    return 0;
}
