#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
int T,n,a[MAXN],m,b[MAXN],c[MAXN];
map<int,int> apper,be;
signed main(){
	scanf("%d",&T);
	while(T--){
		apper.clear();be.clear();
		scanf("%d",&n);
		for(int i = 1;i<=n;i++){
			scanf("%d",a+i);
		}
		for(int i = 1;i<=n;i++){
			scanf("%d",b+i);
			apper[b[i]]++;
		}
		scanf("%d",&m);
		for(int i = 1;i<=m;i++){
			scanf("%d",c+i);
			be[c[i]]++;
		}
		if(apper.find(c[m])==apper.end()) puts("no");
		else{
			bool bj = 1;
			for(int i = 1;i<=n;i++){
				if(a[i]!=b[i]){
					if(!be[b[i]]){
						bj = 0;
						break;
					}
					be[b[i]]--;
				}
			}
			if(bj) puts("yes");
			else puts("no");
		}
	}
	return 0;
}

