#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
signed main(){
	scanf("%d%d%d%d",&n,&a,&b,&c);
	int d = min(a,b);int e = max(a,b);
	if(d<=c&&c<=e&&c!=a) puts("Yes");
	else puts("No");
	return 0;
}

