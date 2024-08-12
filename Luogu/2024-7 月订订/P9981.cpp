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
	const int INF = 0x3f3f3f3f3F3F3F3F;
    //Hash
    int n,m;
    int hash_base1 = 2011111;
    int hash_base2 = 19491001;
    int qpow[MAXN];
    vector<pair<int,int>> v[MAXN];
    //Topo
    int dis[MAXN],rnk[MAXN],rd[MAXN],sum[MAXN];
    vector<int> topo,c[MAXN];
    void Topo(){
        queue<int> q;
        for(int i = 1;i<=n;i++){
            if(!rd[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int k = q.front();q.pop();
            topo.push_back(k);
            for(auto i:v[k]){
                if(--rd[i.first]==0){
                    q.push(i.first);
                }
            }
        }
        reverse(topo.begin(),topo.end());
    }
    void DP(){
        for(int i:topo){
            for(auto j:v[i]){
                if(dis[j.first]+1>dis[i]){
                    dis[i] = dis[j.first]+1;
                }
            }
            c[dis[i]].push_back(i);
        }
        for(int i = 0;i<=n;i++){
            priority_queue<pair<pair<int,int>,int>> pq;
            for(int j:c[i]){
            pair<int,int> now_rk = {-INF,-INF};
                for(auto k:v[j]){
                    if(dis[k.first]+1==dis[j]){
                        if(make_pair(-k.second,-rnk[k.first])>now_rk){
                            now_rk = make_pair(-k.second,-rnk[k.first]);
                            sum[j] = sum[k.first]+k.second;
                        }
                    }
                }
                pq.push({now_rk,j});
            }
            int k = 0;
            while(!pq.empty()){
                auto tmp = pq.top();pq.pop();
                rnk[tmp.second] = ++k;
            }
        }
    }
    signed main(){
        read(n);read(m);
        for(int i = 1;i<=m;i++){
            int uu,vv,ll;
            read(uu);read(vv);read(ll);
            v[uu].push_back({vv,ll});
            rd[vv]++;
        }
        Topo();
        DP();
        for(int i = 1;i<=n;i++){
            write(dis[i],' ');write(sum[i],'\n');
        }
        return 0;
    }
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T = 1;
//	gtx::read(T);
    while(T--) gtx::main();
    return 0;
}
