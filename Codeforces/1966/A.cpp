#include<bits/stdc++.h>
using namespace std;
const int MAXN = 120;
int T,n,m,a[MAXN],ans;
map<int,int> mp;
priority_queue<int> pq;
signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i = 1;i<=n;i++){
			scanf("%d",a+i);
			mp[a[i]]++;
		}
		while(!pq.empty())pq.pop();
		for(auto tmp:mp){
			pq.push(tmp.second);
		}
		int sum = 0;ans = 0;
		while(!pq.empty()){
			auto x = pq.top();pq.pop();
			x += sum;
			if(x<m){
				break;
			}
			sum = x-m+1;
			ans += x-sum;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}

