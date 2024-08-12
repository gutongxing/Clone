#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int a[210],b[210];
struct node{
	int id,x;
}k[410];
bool cmp(node a,node b){
	return a.id<b.id;
}
int cnt;
signed main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		int x;
		cin >> x;
		k[++cnt] = {x,1};
	}
	for(int i = 1;i<=m;i++){
		int x;
		cin >> x;
		k[++cnt] = {x,2};
		
	}
	sort(k+1,k+1+cnt,cmp);
	for(int i = 2;i<=cnt;i++){
		if(k[i].x==1&&k[i-1].x==1){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}

