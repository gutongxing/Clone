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
int n,m;
vector<pair<int,int>> v[MAXN];
vector<int> g[MAXN];
int maxn,maxi;
void dfs(int x,int fath,int sum){
	if(sum >= maxn){
		maxn = sum;
		maxi = x;
	}
	for(auto i:v[x]){
		if(i.first == fath) continue;
		dfs(i.first,x,sum+i.second);
	}
}
bool check(int x){
	int now = 0,k = 0;
	for(int i = 1;i<n;i++){
		if(now>=x){
			now = 0;
			k++;
		}
		now += *(g[i].begin());
	}
	if(now>=x){
		now = 0;
		k++;
	}
	return k>=m;
}
signed main(){
//	freopen("track.in","r",stdin);
//	freopen("track.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);read(m);
	bool tag = 1,tag1 = 1;int sum = 0;
	for(int i = 1;i<n;i++){
		int x,y,z;
		read(x);read(y);read(z);
		sum += z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
		g[x].push_back(z);
		if(x!=1) tag = 0;
		if(x!=y-1) tag1 = 0;
	}
	if(m==1){
		maxn = 0;maxi = 0;
		dfs(1,0,0);
		dfs(maxi,0,0);
		write(maxn);
	}else if(tag){
		sort(g[1].begin(),g[1].end());
		reverse(g[1].begin(),g[1].end());
		write(g[1][m-1]);
	}else if(tag1){
		int l = 0,r = sum,ans = 0;
		while(l<=r){
			int mid = (l+r)>>1;
			if(check(mid)){
				l = mid+1;
				ans = mid;
			}else{
				r = mid-1;
			}
		}
		write(ans);
	}
	return 0;
}

