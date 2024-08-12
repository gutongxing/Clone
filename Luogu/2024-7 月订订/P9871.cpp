#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
#define endl '\n'
#define int long long
//Fast IO
void read(int &x){
	int k = 1;
	x = 0;
	char tmp;
	do{tmp = getchar();if(tmp=='-') k*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
	x*=k;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	stack<int> st;
	while(x) st.push(x%10),x/=10;
	while(!st.empty()) putchar(st.top()+'0'),st.pop();
}
void write(char x){
	putchar(x);
}
void write(int x,char y){
	write(x);write(y);
}
const int MAXN = 1010;
int id,T,n,m,k,d,maxn;
int f[MAXN][MAXN];
vector<pair<int,int>> v[MAXN];
signed main(){
//	freopen("P9871_1.in","r",stdin);
//	freopen("P9871_1.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(id);read(T);
	while(T--){
		memset(f,0,sizeof(f));
		read(n);read(m);read(k);read(d);
		for(int i = 1;i<=m;i++){
			int x,y,w;
			read(x);read(y);read(w);
			v[x].push_back({y,w});
		}
		int maxn = 0;
		for(int i = 1;i<=n;i++){
			if(i==2){
				int x = 0;
			}
			f[i][0] = maxn;
			auto now = v[i].begin();
			int sum = 0;
			for(int j = 1;j<=k;j++){
				while(now!=v[i].end()){
					if(now->first>j) break;
					sum += (now++)->second;
				}
				f[i][j] = f[i-1][j-1]-d+sum;
				if(j>i){
					f[i][j] = -INF;
				}
				maxn = max(maxn,f[i][j]);
//				cout << i << " " << j << " " << f[i][j] << endl;
			}
		}
		write(maxn,endl);
	}
	return 0;
}
