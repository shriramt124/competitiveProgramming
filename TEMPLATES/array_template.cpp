#include<iostream>
using namespace std;
#include<vector>

template<typename T>
T sum_array(const vector<T>&arr){
    T sum = 0;
    for(T ele:arr){
        sum+=ele;
    }
    return sum;
}
template<typename T>
void print_array(const vector<T>&arr){
       for(const T ele: arr){
        cout<<ele<<" ";
       }
       cout<<endl;
}


int main(int argc, char const *argv[])
{
vector<int>arr =  {1,2,4,5,6};
vector<double>b = {2.23,3.4,5.23,45.6};
cout<<"sum of integer array "<<sum_array(arr)<<endl;
cout<<"Sum of double array "<<sum_array(b)<<endl;

print_array(arr);
print_array(b);
    
    return 0;
}
