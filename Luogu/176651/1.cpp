#include<bits/stdc++.h>
using namespace std;
struct node{
    bool operator < (const int a,const int b){
        return a>b;
    }
}
priority_queue<int,vector<int>,greator<node>> pq;
signed main(){
    pq.push(1);
    pq.push(2);
    pq.push(3);
    cout << pq.top();
    return 0;
}