#include<bits/stdc++.h>
using namespace std;
const int MAXN = 30;
int T,n;
char a[MAXN];
signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",a+1);
		n = strlen(a+1);
		if(a[1]!='1') puts("No");
		else{
			bool fg = 1;
			for(int i = n;i>=2;i--){
				if(a[i]=='0'-1){
					a[i] = '9';
				}
				if(a[i]=='9'){
					fg = 0;
					break;
				}
				a[i-1] --;	
			}
			if(fg) puts("YES");
			else puts("no");
		}
	}
	return 0;
}
