#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500010],pos[500010];
vector<pair<int,int>> v;
signed main(){
	scanf("%lld",&n);
	for(int i = 1;i<=n;i++){
		scanf("%lld",a+i);
		pos[a[i]] = i;
	}
	for(int i = 1;i<n;i++){
		if(a[i]!=i){
			v.push_back({i,pos[i]});
			int tmp = pos[a[i]],ttmp = pos[i],tttmp = a[i];
			swap(a[i],a[pos[i]]);
			pos[i] = tmp;pos[tttmp] = ttmp;
//			for(int i = 1;i<=n;i++){
//				cout << pos[i] << " ";
//			}
//			cout << endl;
		}
	}
	printf("%lld\n",v.size());
	for(auto i:v){
		printf("%lld %lld\n",min(i.first,i.second),max(i.first,i.second));
	}
	return 0;
}

