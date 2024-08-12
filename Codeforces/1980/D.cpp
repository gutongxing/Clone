#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
int T,n,a[MAXN];
int gcd[MAXN];
bool pre[MAXN],suc[MAXN];
map<int,int> apper,be;
signed main(){
	scanf("%d",&T);
	while(T--){
		apper.clear();be.clear();
		scanf("%d",&n);
		for(int i = 1;i<=n;i++){
			scanf("%d",a+i);
			if(i>1) gcd[i] = __gcd(a[i],a[i-1]);
		}
		gcd[0] = gcd[1] = 0;
		gcd[n+1] = 0x3f3f3f3f;
		pre[1] = pre[2] = true;
		for(int i = 3;i<=n;i++){
			pre[i] = pre[i-1]&&(gcd[i]>=gcd[i-1]);
		}
		suc[n] = suc[n-1] = true;
		for(int i = n-2;i>=1;i--){
			suc[i] = suc[i+1]&&(gcd[i+1]<=gcd[i+2]);
		}
		bool fg = 0;
		for(int i = 2;i<n;i++){
			int g = (__gcd(a[i-1],a[i+1]));
			if(pre[i-1]&&suc[i+1]&&g>=gcd[i-1]&&g<=gcd[i+2]){
				fg = 1;
				break;
			}
		}
		if(fg||pre[n-1]||suc[2]) puts("Yes");
		else puts("No");
	}
	return 0;
}

