#include<bits/stdc++.h>
using namespace std;
int T;
signed main(){
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		if(m>n) puts("No");
		else if((n-m)%2==0) puts("YES");
		else puts("no");
	}
	return 0;
}

