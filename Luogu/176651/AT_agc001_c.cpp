#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 3e5+10;
const int MOD = 998244353;
int n,m,q;
vector<int> v[MAXN];
void read(int &x){
	x = 0;int p = 1;char ch;
	do{
		ch = getchar();
		if(ch=='-') p = -1;
	}while(!isdigit(ch));
	while(isdigit(ch)){
		x*=10;
		x+=ch-'0';
		ch = getchar();
	}
	x*=p;
}
void write(int k){
	if(k<0) write('-');
	k = abs(k);
	stack<int> num;
	do{
		num.push(k%10);
		k/=10;
	}while(k);
	while(!num.empty()){
		putchar(num.top()+48);
		num.pop();
	}
}
bool vis[MAXN];
vector<int> chain;
int maxn,maxd,maxp[MAXN],project[MAXN],from[MAXN];
void dfs1(int x,int d,int fath){
    from[x] = fath;
    vis[x] = 1;
    for(int i:v[x]){
        if(i==fath) continue;
        dfs1(i,d+1,x);
    }
    if(maxd<d){
        maxn = x;
        maxd = d;
    }
}
void DFS(int x,int d,int fath){
    from[fath] = x;
    vector<pair<int,int>> g;
    for(int i:v[x]){
        if(i==fath) continue;
        DFS(i,d+1,x);
        g.push_back({maxp[i],project[i]});
    }
	if(g.size()==0){
		project[x] = 1;
		return;
	}
    sort(g.begin(),g.end());
	maxp[x] = g[0].first+1;
    if(g.size()==1){
        project[x] = g[0].second;
        return;
    }
    if(g[0].first==g[1].first){
        int now = 0;
        while(now<g.size()&&g[now].first==g[0].first){
            project[x] += g[now].second;
            project[x] %= MOD;
			now++;
        }
    }else{
        int now = 1;
        while(now<g.size()&&g[now].first==g[1].first){
            project[x] += g[now].second;
            project[x] %= MOD;
			now++;
        }
        project[x] *= g[0].second;
    }
}
void find(int x){
    if(!x) return;
    chain.push_back(x);
    find(from[x]);
}
int sum;
signed main(){
    read(n);int k;read(k);sum = n;
    for(int i = 1;i<n;i++){
        int x,y;
        read(x);read(y);++sum;
        v[x].push_back(sum);
        v[sum].push_back(x);
        v[y].push_back(sum);
        v[sum].push_back(y);
    }
    dfs1(1,0,0);
    dfs1(maxn,0,0);
    find(maxn);
    int now = chain[chain.size()/2];
    DFS(now,0,0);
    if(k==(maxd+1)/2+1){
        puts("0");
        return 0;
    }
	vector<pair<int,int>> g;
	for(int i:v[now]){
		g.push_back({maxp[i],project[i]});
	}
	if(g.size()==1){
		write(project[now]);
	}else{
		if(g[0].first==g[1].first){
			int p = 0,ans = 0;
			while(p<g.size()&&g[p].first==g[0].first){
				ans += g[p].second*(project[now]-g[p].second)%MOD;
				ans%=MOD;
				p++;
			}
			write(ans*499122177%MOD);
		}else{
			write(project[now]);
		}
	}
    return 0;
}
