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
void write(int x){
	if(x==0) putchar('0');
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
const int MOD = 1e4+7;
const int MAXN = 1e5+10;
map<int,vector<pair<int,int>>> odd,even;
int n,m,number[MAXN],color[MAXN],ans = 0; 
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n);read(m);
	for(int i = 1;i<=n;i++) read(number[i]),number[i]%=MOD;
	for(int i = 1;i<=n;i++) read(color[i]);
	for(int i = 1;i<=n;i+=2) odd[color[i]].push_back({i,number[i]});
	for(int i = 2;i<=n;i+=2) even[color[i]].push_back({i,number[i]});
	for(auto tmp1:even){
		auto tmp = tmp1.second;
		if(tmp.size()<2) continue;
		int sum = 0;
		for(auto i:tmp) sum += i.second,sum%=MOD;
		for(auto i:tmp) ans += (i.first*sum%MOD+i.first*(tmp.size()-2)%MOD*i.second%MOD)%MOD,ans%=MOD;
	}
//	write(ans,'\n');
	for(auto tmp1:odd){
		auto tmp = tmp1.second;
		if(tmp.size()<2) continue;
		int sum = 0;
		for(auto i:tmp) sum += i.second,sum%=MOD;
		for(auto i:tmp) ans += (i.first*sum%MOD+i.first*(tmp.size()-2)%MOD*i.second%MOD)%MOD,ans%=MOD;
	}
	write(ans);
	return 0;
}

