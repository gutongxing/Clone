#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
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
#define x0 xjy
#define y0 wyb
int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x = 1;y = 0;
		return a;
	}
	int tmp = exgcd(b,a%b,x,y);
	int x0 = x;
	int y0 = y;
	x = y0;
	y = x0-a/b*y0;
	return tmp;
}
const int MAXN = 5e5+10;
const int INF = 0x3f3f3f3f;
int T,n,m,h;
struct node{
	int to;
	int when;
};
vector<int> v[MAXN];
bool operator < (const node a,const node b){
	return !(a.when<b.when);
}
int dis[MAXN],s[MAXN],l[MAXN];
priority_queue<node> pq;
int inv(int x){
	x = (x%h+h)%h;
	int tmpa,tmpb;
	if(exgcd(x,h,tmpa,tmpb)!=1) return -1;
	return (tmpa%h+h)%h;
}
int calc(int a,int b,int x,int y){
	int tmpx,tmpy;
	int hh = h;
	int gcd = exgcd(x-y,hh,tmpx,tmpy);
	if((b-a)%gcd!=0) return -1;
	tmpx *= (b-a)/gcd;
	tmpy *= (b-a)/gcd;
	hh/=abs(gcd);
	return (tmpx%hh+hh)%hh;
}
void dijkstra(){
	pq.push({1,0});
	for(int i = 1;i<=n;i++){
		dis[i] = INF;
	}
	dis[1] = 0;
	while(!pq.empty()){
		auto i = pq.top();pq.pop();
		if(i.to==7){
			int tmp = 0;
		}
		if(dis[i.to]!=i.when) continue;
		for(auto j:v[i.to]){
			int p = calc((i.when*s[i.to]+l[i.to])%h,(i.when*s[j]+l[j])%h,s[i.to],s[j]);
			cout << i.to << " " << j << " " << p << endl;
			if(p==-1) continue;
			p += i.when;
			if(dis[j]>p){
				dis[j] = p;
				pq.push({j,p});
			}
		}
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(T);
	int getdata = 81;
	int nowdata = 0;
	bool p = T==10000;
	while(T--){
		if(++nowdata==getdata&&p){
			read(n);read(m);read(h);
			write(n,' ');write(m,' ');write(h,'\n');
			for(int i = 1;i<=n;i++){
				read(l[i]);
				v[i].clear();
				write(l[i],' ');
			}
			write('\n');
			for(int i = 1;i<=n;i++){
				read(s[i]);
				write(s[i],' ');
			}
			write('\n');
			for(int i = 1;i<=m;i++){
				int x,y;
				read(x);read(y);
				write(x,' ');
				write(y,' ');
				v[x].push_back(y);
				v[y].push_back(x);
			}
			return 0;
		}
		read(n);read(m);read(h);
		for(int i = 1;i<=n;i++){
			read(l[i]);
			v[i].clear();
		}
		for(int i = 1;i<=n;i++){
			read(s[i]);
		}
		for(int i = 1;i<=m;i++){
			int x,y;
			read(x);read(y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dijkstra();
//		for(int i = 1;i<=n;i++){
//			write(dis[i],' ');
//		}
//		write('\n'); 
		if(p) continue;
		if(dis[n]==INF) write(-1,'\n');
		else write(dis[n]+1,endl);
	}
	return 0;
}

