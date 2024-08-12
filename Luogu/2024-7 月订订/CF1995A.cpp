// Problem: A. Diagonals
// Contest: Codeforces - Codeforces Round 961 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1995/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
namespace gtx{
//	Fast IO
	void read(int &x){
		x = 0;int h = 1;char tmp;
		do{tmp=getchar();if(tmp=='-')h*=-1;}while(!isdigit(tmp));
		while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
		x*=h;
	}
	void read(char &x){do{x=getchar();}while(x==' '||x=='\n'||x=='\r');}
	void write(char x){putchar(x);}
	void write(int x){
		if(x<0) putchar('-'),x=-x;int st[200]={0},tot=0;
		do{st[++tot]=x%10,x/=10;} while(x);
		while(tot){putchar(st[tot--]+'0');};
	}
	void write(int x,char y){write(x);write(y);}
	const int MAXN = 120;
	int n,k;
	priority_queue<int> pq;
	signed main(){
		read(n);
		while(!pq.empty()) pq.pop();
		for(int i = 1;i<=n;i++) pq.push(i);
		for(int i = 1;i<n;i++) pq.push(i);
		read(k);
		int cnt = 0;
		if(!k) return write(cnt,'\n'),0;
		while(!pq.empty()){
			int p = pq.top();pq.pop();
			if(k<=p){
				write(cnt+1,'\n');
				return 0;
			}
			k-=p;
			cnt++;
		}
		return 0;
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
	gtx::read(T);
	while(T--) gtx::main();
	return 0;
}
