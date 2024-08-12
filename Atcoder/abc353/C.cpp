#include<bits/stdc++.h>
using namespace std;
const __int128 mod = 1e8;
int n;__int128 ans,sum,sum1;
vector<__int128> st;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		long long x;
		cin >> x;
		st.push_back(x);sum1+=x;
	}
	sort(st.begin(),st.end());
	int pos = 0;
	for(auto i:st){++pos;
		if(i<=mod/2){
			auto sum = lower_bound(st.begin(),st.end(),mod-i);
			if(sum!=st.end())ans -= (st.end()-sum)*mod;
		}else{
			ans -= (n-pos)*mod;
		}
		cout << (long long) ans << endl;
		sum1 -= i;
		ans += (__int128)i*(n-pos)+sum1;
		cout << (long long) ans << endl;
	}
	cout << (long long)ans;
	return 0;
}

