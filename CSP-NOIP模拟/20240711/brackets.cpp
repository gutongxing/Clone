#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
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
const int MAXN = 2300;
int ans;
char a[MAXN];
vector<int> v[MAXN];
int s[MAXN];
char u[MAXN]; 
void dfs(int x,int sum){
	for(int i:v[x]){
		s[sum+1] = s[sum]+(a[i]=='('?1:-1);
		u[sum+1] = a[i];
		dfs(i,sum+1);
	}
	map<int,int> mp;
	int p = 0;
	for(int i = sum;i>=1;i--){
		if(u[i]==')') mp[s[i]]++;
		else p += mp[s[i]-1];
	}
//	cout << x << " " << p << endl;
	ans ^= p*x;
}
int n;
signed main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	read(n);
	for(int i = 1;i<=n;i++) read(a[i]);
	for(int i = 2;i<=n;i++){
		int x;
		read(x);
		v[x].push_back(i); 
	}
	s[1] = (a[1]=='('?1:-1);
	u[1] = a[1];
	dfs(1,1);
	printf("%d",ans);
	return 0;
}
