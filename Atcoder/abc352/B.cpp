#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
char a[MAXN],b[MAXN];
signed main(){
	scanf("%s%s",a+1,b+1);int n = strlen(b+1);int tmp = 1;
	for(int i = 1;i<=n;i++){
		if(b[i]==a[tmp]){
			tmp++;
			cout<<i << " ";
		}
	}
	return 0;
}

