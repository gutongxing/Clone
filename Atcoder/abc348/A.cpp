#include<bits/stdc++.h>
using namespace std;
signed main(){
	int n,sum =0 ;
	cin >> n;
	for(int i = 1;i<n;i++){
		int x;
		cin >> x;sum+=x;
	}
	cout << -sum;
	return 0;
}
