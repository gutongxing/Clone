#include<bits/stdc++.h>
using namespace std;
int T,a[2000];
signed main(){
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int minn = INT_MAX;
		for(int i = 1;i<=n;i++){
			scanf("%d",a+i);minn = min(a[i],minn);a[i+n] = a[i];
		}
		int l = 1,r = n;
		bool pd = 0;
		while(l<=n){
			bool fg = 1;
			for(int i = l+1;i<=r;i++){
				if(a[i]<a[i-1]){
					fg = 0;
					break;
				}
			}
			if(fg){
				pd = 1;
				break;
			}
			l++;r++;
		}
		if(pd) puts("yes");
		else puts("no");
	}
	return 0;
}

