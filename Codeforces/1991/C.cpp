// Problem: Absolute Zero
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1991C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
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
	const int MAXN = 2e5+10;
	int a[MAXN];
	set<int> mt;
	signed main(){
		int n;mt.clear();
		read(n);
		for(int i = 1;i<=n;i++){
			read(a[i]);
			// if((a[i]&1)!=(a[1]&1)) return puts("-1"),0;
			mt.insert(a[i]);
		}
		vector<int> ans;
		int times = 0;
		while(*mt.begin()!=0||*mt.rbegin()!=0){
			int mid = (*mt.begin()+*mt.rbegin())/2;
			if(++times>40) return puts("-1"),0;
			vector<int>v;
			auto tmp = mt.begin();
			while(tmp!=mt.end()){
				v.push_back(abs(*tmp-mid));
				tmp++;
			}
			mt.clear();
			for(int i:v) mt.insert(i);
			ans.push_back(mid);
		}
		write(ans.size(),'\n');
		for(int i:ans) write(i,' ');
		write(endl);
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
