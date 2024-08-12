#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int X = 200010;
int n,m,x,y,z,dis[X],s;
bool flag[X];
struct tree{
	int to,w;
};
vector<tree> a[X];
priority_queue<tree> q;
bool operator < (const tree &a,const tree &b){
	return a.w>b.w;
}
int ans,w[X];
signed main(){
	scanf("%lld%lld",&n,&m);s = 1;
	for(int i = 1;i<=n;i++){
		scanf("%lld",&w[i]);
	}
	for(int i = 1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	for(int i = 1;i<=n;i++){ 
		dis[i] = INF; 
	} 
//	for(int i = 0;i<a[1].size();i++){
//		q.push(a[1][i]);
//		dis[a[1][i].to] = a[1][i].w;
//	} 
//	flag[1] = true;
	q.push({s,w[1]}); 
	dis[s] = 0;
	while(!q.empty()){
		tree tmp = q.top();
		q.pop();
		if(flag[tmp.to]) continue;
		flag[tmp.to] = true;
//		ans += tmp.w;
		for(tree j:a[tmp.to]){ 
			if(flag[j.to]) continue; 
			if(dis[j.to]>j.w+tmp.w+w[j.to]){ 
				q.push({j.to,j.w+tmp.w+w[j.to]}); 
				dis[j.to] = j.w+tmp.w+w[j.to]; 
			} 
		} 
	} 
	for(int i = 2;i<=n;i++){
		printf("%lld ",dis[i]);
	}
	return 0;
}
