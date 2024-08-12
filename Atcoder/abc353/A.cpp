#include<bits/stdc++.h>
using namespace std;
int a[120];
signed main(){
	int n,ans = -1;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i]>a[1]){
			printf("%d",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}

