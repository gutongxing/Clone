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
    #define int long long
    const int MAXN = 1e4+10;
    const int MAXK = 110;
    const int INF = 0x3f3f3f3f3f3f3f3f;
    int dis[MAXN][MAXK],n,m,k;
    struct node{
        int to,mod,w;
    };
    vector<pair<int,int>> v[MAXN];
    bool operator < (const node a,const node b){
        return !(a.w<b.w);
    }
    priority_queue<node> pq;
    void dijkstra(int ti){
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<k;j++){
                dis[i][j] = INF;
            }
        }
        dis[1][0] = ti;
        pq.push({1ll,0ll,ti});
        while(!pq.empty()){
            auto tmp = pq.top();pq.pop();
            if(dis[tmp.to][tmp.mod]!=tmp.w) continue;
            for(auto i:v[tmp.to]){
                int now = tmp.w+1;
                if(now<i.second) continue;
                if(dis[i.first][now%k]>now){
                    dis[i.first][now%k] = now;
                    pq.push({i.first,now%k,now});
                }
            }
        }
    }
    int ans = INF;
    bool check(int k){
        dijkstra(k);
        if(dis[n][0]==INF) return false;
        ans = min(ans,dis[n][0]);
        return true;
    }
	signed main(){
        read(n);read(m);read(k);
        int maxn = 0;
        for(int i = 1;i<=m;i++){
            int x,y,z;
            read(x);read(y);read(z);
            v[x].push_back({y,z});
            maxn = max(maxn,z);
        }
        int l = 0,r = (maxn-1)/k+1;
        while(l<=r){
            int mid = (l+r)>>1;
            if(check(mid*k)){
                r = mid-1;
            }else l = mid+1;
        }
        if(ans==INF) write(-1ll);
        else write(ans);
		return 0;
	}
}
signed main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
//	gtx::read(T);
	while(T--) gtx::main();
	return 0;
}
