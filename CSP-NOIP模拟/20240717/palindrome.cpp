#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2) 
#define endl '\n'
//#define int long long
//Fast IO
inline void read(int &x){
	x = 0;int h = 1;char tmp;
	do{tmp=getchar();if(tmp=='-')h*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
	x*=h;
}
inline void read(char &x){do{x=getchar();}while(x==' '||x=='\n'||x=='\r');}
inline void write(char x){putchar(x);}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;int st[200]={0},tot=0;
	do{st[++tot]=x%10,x/=10;} while(x);
	while(tot){putchar(st[tot--]+'0');};
}
inline void write(int x,char y){write(x);write(y);}
const int MAXN = ((int)5e5+10)<<1;
int a[MAXN],n,use[MAXN];
int l,r;
list<int> be; 
inline bool dfs(int k,string x){
//	cout << x << endl;
//	for(int i:be){
//		cout << i << " ";
//	}
//	cout << endl;
	if((int)x.size()==2*n){
		bool flag = 1;
		auto tmp = be.begin();
		auto tmp1 = be.rbegin();
		for(register int i = 1;i<=n;i++){
			if(*tmp!=*tmp1) flag = 0;
			tmp++;
			tmp1++;
		}
		if(!flag) return false;
		cout << x << endl;
		return true; 
	}
	be.push_back(a[l++]);
	if(dfs(k+1,x+'L')) return true;
	l--;
	be.pop_back();
	be.push_back(a[r--]);
	if(dfs(k+1,x+'R')) return true;
	be.pop_back();
	r++;
	return false;
}
inline void work(){
	cin >> n;
	for(register int i = 1;i<=2*n;i++){
		cin >> a[i];
	}
	l = 1;r = 2*n;
	be.clear();
	if(!dfs(0,"")){
		cout << -1 << endl;
	}
}
signed main(){
	freopen("palindrome.in","r",stdin);
	freopen("palindrome.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--) work();
	return 0;
}

