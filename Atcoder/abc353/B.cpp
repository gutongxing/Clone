#include<bits/stdc++.h>
using namespace std;
int n,k,a[120],ans,now;
signed main(){
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(now+a[i]<=k){
			now+=a[i];
		}else ans++,now = a[i];
	}
	cout << ans+1;
	return 0;
}

