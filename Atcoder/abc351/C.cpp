#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
stack<int> q;
void print(stack<int> q){
	while(!q.empty()) printf("%d ",q.top()),q.pop();
	puts("");
}
signed main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i = 1;i<=n;i++){
		while(!q.empty()&&q.top()==a[i]){
			q.pop();a[i]++;
		}
		q.push(a[i]);
	}
	printf("%d",q.size());
	return 0;
}

