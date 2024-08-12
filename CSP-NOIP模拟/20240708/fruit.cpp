#include<bits/stdc++.h>
#define list ILOVELUOGU
using namespace std;
#define endl '\n'
//#define int long long
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
void write(int x,char p){
	write(x);write(p);
}
const int MAXN = 4e5+10;
int n,a[MAXN],max0,max1,lst0,lst1;
vector<int> ans[MAXN];
int pre[MAXN],nxt[MAXN],tail[MAXN];
void Link(int x,int y){
	pre[y] = x;
	nxt[x] = y;
	tail[x] = tail[y];
}
void Cut(int x,int y){
	pre[y] = 0;
	nxt[x] = 0;
}
int get_tail(int x){
	if(x==tail[x]) return x;
	return tail[x] = get_tail(tail[x]);
}
vector<int> v;
signed main(){
//	freopen("fruit.in","r",stdin);
//	freopen("fruit.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);
	for(int i = 1;i<=n;i++){
		read(a[i]);
		tail[i] = i;
	}
	for(int i = 1;i<n;i++){
		if(a[i]==a[i+1]) Link(i,i+1);
	}
	for(int i = 1;i<=n;i++){
		if(!pre[i]) v.push_back(i);
	}
	while(!v.empty()){
		for(int i:v) write(i,' ');
		write(endl);
		vector<int> g;
		for(int i = 0;i<v.size();i++){
			if(nxt[v[i]]){
				if(!pre[v[i]]) g.push_back(nxt[v[i]]); 
				int cnt = 0;
				int j = i+1;
				for(;j<v.size()&&!nxt[v[j]];j++){
					cnt++;
				}
				if(cnt&1){
					if(j!=v.size()) Link(get_tail(nxt[v[i]]),nxt[v[j]]),pre[v[j]] = 1;
					Cut(v[i],nxt[v[i]]);
					i = j-1;
				}else{
					Cut(v[i],nxt[v[i]]);
					i = j-1;
				}
			}
		}
		v = g;
	}
	return 0;
}

