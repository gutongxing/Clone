#include<bits/stdc++.h>
using namespace std;
int n,q,vis[1020];
signed main(){
	scanf("%d%d",&n,&q);
	for(int i = 1;i<=q;i++){
		int x;
		scanf("%d",&x);
		if(vis[x]) n++;
		else n--;
		vis[x]^=1;
	}
	printf("%d",n);
	return 0;
}

