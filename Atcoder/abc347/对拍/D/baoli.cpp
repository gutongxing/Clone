#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
long long s[200005];
long long ans;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		for(int j=2;j<=sqrt(a[i]);j++)
			if(a[i]%j==0){
				while(a[i]%(j*j)==0 && a[i]>1) a[i]/=j*j;
			}
	}
	for(int i=1;i<=n;i++){
//		printf("%d ",a[i]);
		if(a[i]!=0){
			ans+=s[a[i]];
			ans+=s[0];
		}
		else ans+=i-1;
		s[a[i]]++;
	}
//	printf("\n");
	printf("%lld",ans);
	return 0;
}


