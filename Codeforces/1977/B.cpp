#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,len;
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		bitset<32> st(n);
//		cout << st << endl;
		printf("32\n");
		bool fg = 0;
		int ans[32] = {};int x = 1;
		for(int i = 31;i>=0;i--){
			if(st[i]){
				while(i!=32&&st[i-1]){
					st[i+1] = 1;
					int wei = i;
					for(int j = i;j>=0;j--){
						st[j] = st[j]^1;
						if(!st[j]) wei = j;
					}
					for(int j = wei;j>=0;j--) st[j] = st[j]^1;
					ans[i+1] = 1*x;x*=-1;
				}else{
					ans[i] = 1*x;
				}
			}
		}
		ans[0] = st[0];
		for(int i = 0;i<32;i++){
			printf("%d ",ans[i]);
		}
		puts("");
	}
	return 0;
}

