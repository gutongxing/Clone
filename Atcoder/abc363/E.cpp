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
bool flag[1200][1200];
int a[1200][1200];
priority_queue<pair<int,pair<int,int>>,
vector<pair<int,pair<int,int>>>,
greater<pair<int,pair<int,int>>>> pq;
int n,m,p;
void push(int x,int y){
	if(x<1||y<1) return;
	if(x>n||y>m) return;
	if(flag[x][y]) return;
	flag[x][y] = 1;
	pq.push({a[x][y],{x,y}});
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);read(m);read(p);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			read(a[i][j]);
		}
	}
	for(int i = 1;i<=n;++i) push(i,1),push(i,m);
	for(int i = 1;i<=m;++i) push(1,i),push(n,i);
	int now = 1,ans = n*m;
	while(now<=p){
		while(!pq.empty()&&pq.top().first<=now){
			ans--;
			push(pq.top().second.first-1,pq.top().second.second);
			push(pq.top().second.first+1,pq.top().second.second);
			push(pq.top().second.first,pq.top().second.second-1);
			push(pq.top().second.first,pq.top().second.second+1);
			pq.pop();
		}
		now++;
		write(ans,'\n');
	}
	return 0;
}
