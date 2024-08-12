#include<bits/stdc++.h>
#define int long long
using namespace std;
class DSU{
	private:
		int fath[200010];
	public:
		int size[200010],sz[200010];
		int get_father(int x){
			if(x==fath[x]) return x;
			return fath[x] = get_father(fath[x]);
		}
		void init(int x){
			for(int i = 1;i<=x;i++){
				fath[i] = i;
				sz[i] = 1;
			} 
		} 
		void merge(int x,int y){
			int fx = get_father(x);
			int fy = get_father(y);
			if(fx==fy) size[fx]++;
			else{
				fath[fy] = fx;
				sz[fx] += sz[fy];
				size[fx] += size[fy];
				size[fx]++;
			}
		}
}dsu;
int n,m,ans;
map<pair<int,int>,int> mp;
signed main(){
	scanf("%lld%lld",&n,&m);
	dsu.init(n);
	for(int i = 1;i<=m;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		if(mp.find({x,y})==mp.end()){
			mp[{x,y}] = 1;
			mp[{y,x}] = 1;
			dsu.merge(x,y);
		}
	}
	for(int i = 1;i<=n;i++){
		if(i==dsu.get_father(i)){
			ans += 1ll*dsu.sz[i]*(dsu.sz[i]-1)/2-dsu.size[i];
		}
	}
	printf("%lld",ans);
	return 0;
}
