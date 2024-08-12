#include<bits/stdc++.h>
using namespace std;
const int MAXN = 120;
int n,m,k,c[MAXN],a[MAXN][MAXN];
bool r[MAXN];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++){
		scanf("%d",c+i);
		for(int j = 1;j<=c[i];j++){
			scanf("%d",&a[i][j]);
		}
		char o[120];
		scanf("%s",o);
		r[i] = o[0]=='o';
	}
	int ans = 0;
	for(int i = 0;i<(1<<n);i++){
		if(i==1022){
			int x = 0;
		}
		bitset<20> b(i);
		bool fg = 1;
		for(int j = 1;j<=m;j++){
			int sum = 0;
			for(int k = 1;k<=c[j];k++){
				if(b[a[j][k]-1]) sum++;
			}
			if((sum>=k)^r[j]){
				fg = 0;
				break;
			}
		}
		if(fg){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}

