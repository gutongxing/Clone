#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
//Fast IO
void read(int &x){
	int k = 1;
	x = 0;
	char tmp;
	do{tmp = getchar();if(tmp=='-') k*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
	x*=k;
}
void write(int x){
	if(x==0) putchar('0');
	if(x<0) putchar('-'),x=-x;
	stack<int> st;
	while(x) st.push(x%10),x/=10;
	while(!st.empty()) putchar(st.top()+'0'),st.pop();
}
void write(long long x){
	if(x==0) putchar('0');
	if(x<0) putchar('-'),x=-x;
	stack<int> st;
	while(x) st.push(x%10),x/=10;
	while(!st.empty()) putchar(st.top()+'0'),st.pop();
}
void write(char x){
	putchar(x);
}
void write(int x,char y){
	write(x);write(y);
}
void write(long long x,char y){
	write(x);write(y);
}
int n,m,q,u,v,t;
long long delta;
priority_queue<int> pq;
signed main(){
	freopen("earthworm.in","r",stdin);
	freopen("earthworm.out","w",stdout);
	read(n);read(m);read(q);read(u);read(v);read(t);
	for(int i = 1;i<=n;i++){
		int x;
		read(x);
		pq.push(x);
	}
	for(int i = 1;i<=m;i++){
		int x = pq.top();pq.pop();
		long long y = x+delta;
		if(i%t==0){
			write(y,' ');
		}
		long long k = y*u/v;
		long long res = y-k;
		delta += q;
		pq.push(k-delta);
		pq.push(res-delta);
	}
	write(endl);
	int p = 0;
	while(!pq.empty()){
		long long tmp = pq.top()+delta;pq.pop();
		if((++p)%t==0){
			write(tmp,' ');
		}
	}
	return 0;
}
