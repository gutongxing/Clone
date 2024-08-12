#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,iid;
	int x,y;
}a[200010];
int n,pos[200010];
bitset<200001> vis,p;
bool cmp1(node a,node b){
	return a.x>b.x;
}
bool cmp2(node a,node b){
	return a.y<b.y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i].x >> a[i].y;a[i].iid = i;
	}
	sort(a+1,a+1+n,cmp1);
	for(int i = 1;i<=n;i++){
		a[i].id = i;
	}
	sort(a+1,a+1+n,cmp2);
	for(int i = 1;i<=n;i++){
		pos[a[i].id] = i;
	}
	p.set();vis.set();
	vector<int> ans;
	for(int i = 1;i<=n;i++){
		if(vis[pos[i]-1]==0) continue;
		ans.push_back(a[pos[i]].iid);
		auto tmp = (p<<(pos[i]-1))&vis;
		for(int x = tmp._Find_first();x<n;x = tmp._Find_first()){
			vis.flip(x);
			tmp.flip(x);
		}
	}
	sort(ans.begin(),ans.end());
	cout << ans.size() << endl;
	for(int i:ans){
		cout << i << " ";
	}
	return 0;
}

