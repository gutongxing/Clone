#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
int T,n,m;
char a[MAXN];
map<char,int> k;
signed main(){
	scanf("%d",&T);
	while(T--){
		k.clear();
		scanf("%d%d",&n,&m);
		scanf("%s",a+1);
		for(int i = 1;i<=n;i++){
			k[a[i]]++;
		}
		int cnt = 0;
		for(char i = 'A';i<='G';i++){
			cnt+=max(0,m-k[i]);
		}
		printf("%d\n",cnt);
	}
	return 0;
}

