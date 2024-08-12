#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 3e5+10;
int cnt,ans;
struct trie{
	map<char,int> c;
	int bj;
}a[26*MAXN];
void clear(int k){
	a[k].c.clear();
	a[k].bj = 0;
}
int dp[26*MAXN];
void insert(string str){
	int root = 1;
	for(char s:str){
		if(a[root].c.find(s)==a[root].c.end()){
			a[root].c[s] = ++cnt;
			clear(cnt);
		}
		root = a[root].c[s];
	}
	a[root].bj += 1;
}
void DP(int k){
	for(auto tmp:a[k].c){
		DP(tmp.second);
		dp[k] += dp[tmp.second];
	}
	dp[k] += a[k].bj;
	ans += dp[k]*(dp[k]-1)/2;
}
int T,n,q;
string str[MAXN];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		string s;
		cin >> str[i];
	}
	sort(str+1,str+1+n);
	for(int i = 1;i<=n;i++) insert(str[i]);
	DP(1);
	cout << ans-dp[1]*(dp[1]-1)/2;
	return 0;
}
