#include <iostream>
#include <vector>
#include<queue>
#include<map>
using namespace std;
 
int main() {
    
     priority_queue<map<string,int>>pq;
      map<string,int>mp;
      mp["ram"]++;
      mp["arjun"]++;
      mp["arjun"]++;
     pq.push(mp);
          


    return 0;
}
