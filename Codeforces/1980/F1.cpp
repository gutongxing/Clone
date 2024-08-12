#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5+10;
stack<pair<int,pair<int,int>>> st;
int T,n,m,k;
int ans[MAXN];
struct node{
	int x,y,id;
}a[MAXN];
bool cmp(node a,node b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		while(!st.empty()) st.pop();
		for(int i = 1;i<=k;i++){
			scanf("%lld%lld",&a[i].x,&a[i].y);a[i].id = i;
		}
		sort(a+1,a+1+k,cmp);
//		int anss = 0;
		for(int i = 1;i<=k;i++){
			if(a[i].x==a[i-1].x) ans[a[i].id] = 0;
			else{
				int sum = 0;
				while(!st.empty()&&st.top().second.second>=a[i].y){
					ans[st.top().first] = 0;
					auto tmp = st.top();
					st.pop();
					if(st.empty()){
						sum += tmp.second.first*(tmp.second.second-1);  
					}else{
						sum += (tmp.second.first-st.top().second.first)*(tmp.second.second-1);
					}
				}
//				if(st.empty()){
//					anss += a[i].x*(a[i].y-1);
//				}else{
//					ans += 
//				}
				pair<int,pair<int,int>> tmp = {a[i].id,{a[i].x,a[i].y}};
				int uuu = 0;
				if(st.empty()){
					uuu += tmp.second.first*(tmp.second.second-1);  
				}else{
					uuu += (tmp.second.first-st.top().second.first)*(tmp.second.second-1);
				}
				st.push(tmp);
				ans[a[i].id] = sum-uuu;
			}
		}
		int anss = 0;
		st.push({0,{n,m+1}});
		while(!st.empty()){
			auto tmp = st.top();
			st.pop();
			if(st.empty()){
				anss += tmp.second.first*(tmp.second.second-1); 
			}else{
				anss += (tmp.second.first-st.top().second.first)*(tmp.second.second-1);
			}
		}
		printf("%lld\n",anss);
		for(int i = 1;i<=k;i++){
			printf("%lld ",ans[i]);
		}
		puts("");
	}
	return 0;
}

