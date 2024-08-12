#include<bits/stdc++.h>
using namespace std;
const int MAXN = 30;
int T,n;
char a[MAXN],b[MAXN];
signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,a+1);
		memcpy(b,a,sizeof(a));
		sort(a+1,a+1+n);
		bool tag = 1;
		for(int i = 1;i<=n;i++){
			if(a[i]!=b[i]) tag = 0;
		}
		if(tag) puts("YES");
		else puts("NO");
	}
	return 0;
}

