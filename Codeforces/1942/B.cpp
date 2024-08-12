#include<bits/stdc++.h>
using namespace std;
int T,n,now;
signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);now = 0;
		for(int i = 1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(x>0){
				printf("%d ",now);
				now+=x;
			}else{
				printf("%d ",now-x);
			}
		}
		printf("\n");
	}
	return 0;
}
