#include<bits/stdc++.h>
using namespace std;
int T,a,b;
signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		if(b==1){
			for(int i = 1;i<=a;i++){
				printf("%d ",i);
			}
			puts("");
		}else if (b==a){
			for(int i = 1;i<=a;i++){
				printf("%d ",1);
			}
			puts("");
		}else{
			puts("-1");
		}
	}
	return 0;
}
