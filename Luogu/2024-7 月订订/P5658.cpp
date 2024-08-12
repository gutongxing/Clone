#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
//Fast IO
void read(int &x){
	int k = 1;
	x = 0;
	char tmp;
	do{tmp = getchar();if(tmp=='-') k*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
	x*=k;
}
void read(char &x){
	do{x=getchar();}while(x=='\n'||x=='\r'||x==' '); 
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
const int MAXN = 5e5+10;
int n,m,ans = 0,f[MAXN];
vector<int> v[MAXN];
map<int,vector<int>> mp;
struct sta{
	int from,val;
}s[MAXN];
char a[MAXN];
void dfs(int x,int sum){
	if(a[x]==')'){
		auto tmp = lower_bound(mp[s[x].val].begin(),mp[s[x].val].end()-1,s[x].from);
		sum += (mp[s[x].val].end()-1-tmp);
	}
	ans ^= x*sum;
//	cout << x << " " << sum << endl;
	for(int i:v[x]){
		s[i].from = x;
		s[i].val = s[x].val+(a[i]=='('?1:-1);
		while(s[i].from&&s[s[i].from].val>=s[i].val){
			s[i].from = s[s[i].from].from;
		}
		mp[s[i].val].push_back(i);
		dfs(i,sum);
		mp[s[i].val].pop_back();
	}
}
signed main(){
//	freopen("brackets3.in","r",stdin);
//	freopen("brackets.out","w",stdout);
	read(n);
	for(int i = 1;i<=n;i++) read(a[i]);
	for(int i = 2;i<=n;i++){
		int x;
		read(x);
		v[x].push_back(i);
	}
	mp[0].push_back(0);
	s[1].val = (a[1]=='('?1:-1);
	mp[s[1].val].push_back(1);
	dfs(1,0);
	write(ans);
	return 0;
}

