#include<bits/stdc++.h>
using namespace std;
#define int long long
int qpow(int x,int y){
    if(y==1) return x;
    if(y==0) return 1;
    int k = qpow(x,y/2);
    k*=k;k%=998244353;
    if(y&1) k*=x;k%=998244353;
    return k;
}
signed main(){
    cout << qpow(2,998244351);
    return 0;
}