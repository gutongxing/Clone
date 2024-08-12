#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
int T,n,m,k,a[MAXN];
map<int,bool> apper;
signed main(){
	scanf("%d",&T);
	while(T--){
		apper.clear();
		scanf("%d%d%d",&n,&m,&k);a[n+1]=0;
		for(int i = 1;i<=n;i++){
			scanf("%d",a+i);
			apper[a[i]]++;
		}
		m = a[m];
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		if(a[k]>m) puts("no");
		else{
			if(a[k]==m&&a[k]==a[k+1]) puts("maybe");
			else puts("yes");
		}
	}
	return 0;
}

