#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum,wei[200010];__int128 ans;
const int MOD = 998244353;
vector<int> st;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		long long x;
		cin >> x;a[i] = x;
		while(x){
			wei[i]++;
			x/=10;
		}
	}
	for(int i = n;i>=1;i--){
		wei[i] = (__int128)powl(10,wei[i])%MOD;
		sum+=wei[i];sum%=MOD;
		__int128 tmp = (sum-wei[i]);tmp%=MOD;
		ans += a[i]*tmp;ans%=MOD;
		ans += (i-1)*a[i];ans%=MOD;
	}
	cout << (long long) ans;
	return 0;
}

