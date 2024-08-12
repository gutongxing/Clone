#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5+10;
int n,minn,sum,a,b;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a >> b;
		minn = max(minn,b-a);sum+=a;
	}
	cout << sum + minn; 
	return 0;
}

