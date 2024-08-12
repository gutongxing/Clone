#include<bits/stdc++.h>
using namespace std;
string mp[120];
int n,sum;
signed main(){
	cin >> n;
	for(int i = 1;i<=n;i++){
		string x;int y;
		cin >> x >> y;
		mp[i] = x;
		sum += y; 
	}
	sort(mp+1,mp+1+n);
	cout << mp[sum%n+1];
	return 0;
}

