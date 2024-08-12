#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5+10;
//DSU
int fath[MAXN],sz[MAXN];
void init(int x){
    for(int i = 1;i<=x;i++){
        fath[i] = i;
        sz[i] = i;
    }
}
int get_father(int x){
    if(x==fath[x]) return x;
    return fath[x] = get_father(fath[x]);
}
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
int maxn,maxd;
void dfs(int x,int d,int fath){
    vis[x] = 1;
    for(int i:v[x]){
        if(i==fath) continue;
        dfs(i,d+1,x);
    }
    if(maxd<d){
        maxn = x;
        maxd = d;
    }
}
signed main(){
    read(n);read(m);read(q);
    init(n);
    for(int i = 1;i<=m;i++){
        int x,y;
        read(x);read(y);
        v[x].push_back(y);
        v[y].push_back(x);
        int fx = get_father(x);
        int fy = get_father(y);
        fath[fx] = fy;
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            maxd = 0;
            dfs(i,1,0);
            dfs(maxn,1,0);
            sz[get_father(i)] = maxd-1;
        }
    }
    for(int i = 1;i<=q;i++){
        int opt,x,y;
        read(opt);read(x);
        if(opt==1){
            write(sz[get_father(x)]);putchar('\n');
        }else{
            read(y);
            int fx = get_father(x);
            int fy = get_father(y);
            if(fx!=fy){
                fath[fy] = fx;
                sz[fx] = max({sz[fx],sz[fy],(sz[fx]+1)/2+(sz[fy]+1)/2+1});
            }
        }
    }
    return 0;
}