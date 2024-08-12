#include<bits/stdc++.h>
#define int long long
const int MAXN = 2000;
using namespace std;
int T,a[MAXN],n,ans[MAXN],__lcm[MAXN];
int lcm(int a,int b){
	return a*b/__gcd(a,b);
}
map<int,int> mp; 
signed main(){
	scanf("%d",&T);
	while(T--){
		mp.clear();
		scanf("%d",&n);
		for(int i = 1;i<=n;i++){
			scanf("%d",a+i);mp[a[i]]++;
		}
		sort(a+1,a+1+n);
		__lcm[1] = a[1];
		for(int i = 2;i<=n;i++){
			__lcm[i] = lcm(__lcm[i-1],a[i]);
		}
		for(int i = n-1;i>=0;i--){
			if(i){
				if(!mp[__lcm[i]]){
					printf("%d\n",i);
					break;
				}
			}else puts("0"); 
		}
	}
	return 0;
}

