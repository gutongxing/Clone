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
const int MAXN = 2e3+10;
const int MAXK = 210;
int dis[MAXN][MAXK];//到达点i且通过路程为j的最小t
int n,m,k,s,t;
struct node{
	int vertex,sumk,val; 
};
bool operator < (const node a,const node b){
	return !(a.val<b.val);
} 
priority_queue<node> pq;
vector<node> g[MAXN];
void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	dis[s][0] = 0;
	pq.push({s,0,0});
	while(!pq.empty()){
		auto tmp = pq.top();pq.pop();
		if(dis[tmp.vertex][tmp.sumk]!=tmp.val) continue;
//		cout << tmp.vertex << " " << tmp.sumk << " " << tmp.val << endl;
		for(auto p:g[tmp.vertex]){
			if(tmp.sumk+p.sumk>=k) continue;
			if(dis[p.vertex][tmp.sumk+p.sumk]>tmp.val+p.val){
				dis[p.vertex][tmp.sumk+p.sumk] = tmp.val+p.val;
				pq.push({p.vertex,tmp.sumk+p.sumk,tmp.val+p.val});
			}
		}
	}
}
signed main(){
	freopen("hull.in","r",stdin);
	freopen("hull.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(k);read(n);read(m);
	for(int i = 1;i<=m;i++){
		int u,v,t,h;
		read(u);read(v);read(t);read(h);
		g[u].push_back({v,h,t});
		g[v].push_back({u,h,t});
	}
	read(s);read(t);
	dijkstra();
	int minn = 0x3f3f3f3f;
	for(int i = 1;i<k;i++){
		minn = min(minn,dis[t][i]);
	}
	if(minn==0x3f3f3f3f){
		puts("-1");
	}else write(minn);
	return 0;
}

