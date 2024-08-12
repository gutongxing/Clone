#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
//Fast IO
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
int n,m,vis[MAXN];
vector<pair<int,int>> v[MAXN];
bitset<MAXN> c[2];
void dfs(int k,int id,int col){
	if(vis[k]) return;
	c[col].set(id);
	vis[k] = 1;
	for(auto i:v[k]){
		dfs(i.first,i.second,col^1);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);read(m);
	for(int i = 1;i<=m;i++){
		int uu,vv;
		read(uu);read(vv);
		v[uu].push_back({vv,i});
		v[vv].push_back({uu,i});
	}
	for(int i = 1;i<=n;i++) dfs(i,0,0);
	for(int i = 1;i<=m;i++){
		if(c[0][i]){
			write('B');
		}else if(c[1][i]) write('R');
		else{
			write('G');
		}
	}
	return 0;
}

