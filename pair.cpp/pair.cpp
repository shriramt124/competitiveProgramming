#include<iostream>
using namespace std;
 

int main(int argc, char const *argv[])
{
    //decrearing pair 
    pair<int,string>p;//can be any data type 
    pair<int,double>p1;
    pair<int,char>p2;
    //inserting elements in pair 
    p = make_pair(2,"abc");
    //we can also use {} brackets 
    p = {3,"def"};//it will override the above value 
    cout<<p.first<<" "<<p.second<<endl;
    //decearing the array of pairs
    pair<int,string>p3[3];//array of pairs of lenth 3 
    for(int i = 0;i<3;i++){
        cin>>p3[i].first>>p3[i].second;
    }
    for(int i = 0;i<3;i++){
        cout<<p3[i].first<<" "<<p3[i].second<<endl;
    }
    
    return 0;
}
