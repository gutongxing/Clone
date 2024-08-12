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
	const int MAXN = 1e5+10;
	const int INF = 0x3f3f3f3f3f3f3f3f;
	int dis[MAXN],n,m,S,T,l,k;
	struct node{
		int to;
		int dis;
	};
	vector<node> Sk,Tk;
	bool operator < (const node a,const node b){
		return !(a.dis<b.dis);
	}
	vector<node> v[MAXN];
	priority_queue<node> pq;
	void dijkstra(int S){
		for(int i = 1;i<=n;i++){
			dis[i] = INF;
		}
		dis[S] = 0;
		pq.push({S,0});
		while(!pq.empty()){
			auto tmp = pq.top();pq.pop();
			int k = tmp.to;
			int w = tmp.dis;
			if(dis[k]!=w) continue;
			for(auto i:v[k]){
				if(dis[i.to]>w+i.dis){
					dis[i.to] = w+i.dis;
					pq.push({i.to,dis[i.to]});
				}
			}
		}
//		for(int i = 1;i<=n;i++){
//			cout << dis[i] << " ";
//		}
//		cout << endl;
	}
	bool cmp(node a,node b){
		return a.dis<b.dis;
	}
	signed main(){
		read(n);read(m);
		read(S);read(T);read(l);read(k);
		for(int i = 1;i<=m;i++){
			int x,y,z;
			read(x);read(y);read(z);
			v[x].push_back({y,z});
			v[y].push_back({x,z});
		}
		dijkstra(S);
		for(int i = 1;i<=n;i++){
			Sk.push_back({i,dis[i]});
		}
		sort(Sk.begin(),Sk.end(),cmp);
		dijkstra(T);
		for(int i = 1;i<=n;i++){
			Tk.push_back({i,dis[i]});
		}
		sort(Tk.begin(),Tk.end(),cmp);
		reverse(Tk.begin(),Tk.end());
		int ans = 0;
		auto tmp = Tk.begin();
		for(auto i:Sk){
			if(tmp==Tk.end()) break;
			if(dis[i.to]+l+i.dis<=k) ans--;
//			cout << i.to << " " << i.dis << ":" << endl;
			while(tmp!=Tk.end()&&((tmp->dis+i.dis+l)>k)){
//				cout << tmp->to << " " << tmp->dis << endl;
				tmp++;
			}
//			cout << "-----" << endl;
			ans += Tk.end()-tmp;
		}
		write(ans);
		return 0;
	}
}
signed main(){
	freopen("build.in","r",stdin);
	freopen("build.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
//	gtx::read(T);
	while(T--) gtx::main();
	return 0;
}

