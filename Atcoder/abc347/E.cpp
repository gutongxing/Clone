#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int MAXN = 5e5+10;
set<pair<int,int>> st;
int n,q,ans[MAXN],sum[MAXN];
signed main(){
	scanf("%lld%lld",&n,&q);
	for(int i = 1;i<=q;i++){
		int x;
		scanf("%lld",&x);
		auto ite = st.lower_bound({x,0});
		if(ite!=st.end()&&ite->first == x){
			ans[x] += sum[i-1]-sum[ite->second-1];
			st.erase(ite);
		}else{
			st.insert({x,i});
		}
		sum[i] = sum[i-1]+st.size();
	}
	for(auto ite:st){
		ans[ite.first] += sum[q]-sum[ite.second-1];
	}
	for(int i = 1;i<=n;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
