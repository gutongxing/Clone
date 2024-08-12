#include<bits/stdc++.h>
using namespace std;
int n,x,l;
signed main(){
	scanf("%d%d",&n,&x);
	for(int i = 1;i<=n;i++){
		scanf("%d",&l);
		if(l%x==0){
			printf("%d ",l/x);
		}
	}
	return 0;
}
