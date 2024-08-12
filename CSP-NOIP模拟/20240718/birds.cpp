#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
#define double long double
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
const int MAXN = 30;
int T,n,m;
map<pair<double,double>,bitset<MAXN>> mp;
vector<bitset<MAXN>> v;
double x[MAXN],y[MAXN];
int ans = 0x3f3f3f3f;
void dfs(int k,bitset<MAXN> vis,int use){
//	if(use>=ans) return;
//	cout << k << " " << use << " " << vis << " " << vis.count() << endl;
	if(k==v.size()){
		ans = min(ans,use+n-(int)vis.count());
		return;
	}
	dfs(k+1,vis,use);
	dfs(k+1,vis|v[k],use+1);
}
signed main(){
	freopen("birds.in","r",stdin);
	freopen("birds.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n >> m;mp.clear();v.clear();
		for(int i = 1;i<=n;i++){
			cin >> x[i] >> y[i];
		}
		#define x1 x[i]
		#define x2 x[j]
		#define y1 y[i]
		#define y2 y[j]
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				double a = x2*y1-x1*y2;
				if(x1==0) continue;
				if(x2==0) continue;
				if(x1==x2) continue;
				a/=x1*x2*(x1-x2);
				if(a>=0) continue;
				double b = y1/x1-a*x1;
				mp[{a,b}].set(i);
				mp[{a,b}].set(j);
			}
		}
		#undef x1
		#undef x2
		#undef y1
		#undef y2
		for(auto tmp:mp){
			v.push_back(tmp.second);
		}
		ans = 0x3f3f3f3f;
		bitset<MAXN> em;
		dfs(0,em,0);
		cout << ans << endl;
	}
	return 0;
}

