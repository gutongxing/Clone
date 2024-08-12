#include<bits/stdc++.h>
using namespace std;
int T,n,k;
signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i = n-k;i>=1;i--){
			printf("%d ",i);
		}
		for(int i = n-k+1;i<=n;i++){
			printf("%d ",i); 
		}
		puts("");
	}
	return 0;
}

