#include<bits/stdc++.h>
using namespace std;
int T,n,a[200010];
vector<int> ans;
int nxt(int k){
	return (k-1)%n+1;
}
signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 1;i<=n;i++){
			scanf("%d",a+i);
		}
		for(int i = 1;i<=2*n;i++){
			if(a[(i-1)%n+1]<=0){
				ans.push_back(a[nxt(i)]);
			}
			if(a[a[(i-1-1)%n+1]]>0){
				a[nxt(i)] -= a[];
			}
		}
	}
	return 0;
}
