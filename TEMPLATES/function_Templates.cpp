#include<iostream>
using namespace std;
#include<vector>

template <typename T,typename U> T add(T a,U b){
    return a + b;
}

template<typename T>T sumArray(T n){
    vector<T> arr;
    for (int i = 0; i < 5;i++){
        T ele;
        cin >> ele;
        arr.push_back(ele);
    }
    T sum = 0;
    for(auto ele:arr){
        sum += ele;
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    cout << add(4, 5) << endl;
    cout << add(4.5, 5.5) << endl;
    cout << add(4.6, 5) << endl;

    int ans = sumArray(2);
    cout << ans << endl;

    return 0;
}
