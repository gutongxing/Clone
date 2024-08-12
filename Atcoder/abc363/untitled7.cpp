#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
int num[20];
int dp[20][20][2];
int t[20];
ll dfs(int len,int cur,int s,bool lim)
{
	if(cur==0)return s;
	if(!lim&&~dp[len][cur][s])return dp[len][cur][s];
	int up=lim?num[cur]:9;
	ll res=0;
	for(int i=0;i<=up;i++){
		t[cur]=i;
		if(len==cur&&i==0)
			res+=dfs(len-1,cur-1,s,lim&&(i==up));
		else if(s&&cur<=(len+1)/2)
			res+=dfs(len,cur-1,t[len-cur+1]==i,lim&&(i==up));
		else res+=dfs(len,cur-1,s,lim&&i==up);
	}
	if(!lim)dp[len][cur][s]=res;
	return res;
}
ll calc(ll n){
	int len=0;
	while(n)num[++len]=n%10,n/=10;
	return dfs(len,len,1,1);
}
int main()
{
	memset(dp,-1,sizeof dp);
	ll a,k;
	cin>>a>>k;
	ll y=calc(a-1)+k;
	ll l=1,r=1e18+1;
	while(l<r){
		ll mid=l+r>>1;
		if(calc(mid)>=y)r=mid;
		else l=mid+1;
	}
	cout<<r;
}
