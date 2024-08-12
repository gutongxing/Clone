#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int T,n,a[MAXN];
signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		bool fg = 1;
		for(int i = 1;i<=n;i++){
			scanf("%d",a+i);
			if(a[i]!=a[1]) fg = 0;
		}
		if(fg){
			puts("NO");
		}else{
			puts("YES");
			putchar('R');
			putchar('B');
			for(int i = 1;i<n-1;i++) putchar('R'); 
			puts("");
		}
	}
	return 0;
}
