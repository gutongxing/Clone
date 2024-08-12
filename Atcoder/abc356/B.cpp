#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int a[210],b[210];
signed main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=m;i++){
		scanf("%d",a+i);
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			int x;
			scanf("%d",&x);
			b[j] += x; 
		}
	}
	bool bj = 1;
	for(int i = 1;i<=m;i++){
		if(b[i]<a[i]){
			bj = 0;
			break;
		}
	}
	if(bj) puts("Yes");
	else puts("No");
	return 0;
}

