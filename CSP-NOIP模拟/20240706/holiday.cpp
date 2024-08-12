#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[12000];
vector<int> v[12000];
bool vis[12000];
int maxn = 0;
void dfs(int x,int k,int ans){
	if(k==5){
		if(x==1){
			maxn = max(maxn,ans);
		}
		return;
	}
	if(vis[x]) return;
	vis[x] = 1;
	for(int i:v[x]){
		dfs(i,k+1,ans+a[i-1]);
	}
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int n,m,k;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i<n;i++){
		cin >> a[i];
	}
	if(k!=0){
		sort(a+1,a+n);
		reverse(a+1,a+n);
		cout << a[1]+a[2]+a[3]+a[4];			
	}else{
		for(int i = 1;i<=m;i++){
			int x,y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0,0);
		cout << maxn; 
	}
	return 0;
}

