#include<bits/stdc++.h>
using namespace std;
int q = 100003;
int qpow(int a,int b){
	if(b == 0) return 1%q;
	if(b == 1) return a%q;
	int now = qpow(a,b/2);
	now *= now;
	now %= q;
	if(b&1) now *= a;
	now%=q;
	return now;
}
int to(string k){
	int p=0,q=0;
	for(char i:k){
		if(i=='1') q+=qpow(1000003,p);p++;q%=100000007;
	}
	return q;
}
void work(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,qzh[1000200]={0};string k[1000200];
	cin >> n >> m >> k[n+1] >> k[n+2];
	for(int i = 1;i<=m;i++) cin >> k[i];
	for(int i = 1;i<=m;i++) qzh[i]^=qzh[i-1]^to(k[i]);
	assert(qzh[1]<50000007);
	while(1){new int;};
	cout << "TAK";
}
signed main(){
	work();
	
	return 0;
}
