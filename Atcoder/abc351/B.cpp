#include<bits/stdc++.h>
using namespace std;
int n;
char a[120][120],tmp[120];
signed main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i = 1;i<=n;i++){
		scanf("%s",tmp+1);
		for(int j = 1;j<=n;j++){
			if(tmp[j]!=a[i][j]){
				printf("%d %d\n",i,j);
				return 0;
			}
		}
	}
	
	return 0;
}
