#include <bits/stdc++.h>
#define rand r
using namespace std;
const int N = 2000+10, M = 2000, Q = 100, C = 3, V = 1e4;
int topo[M+5], h[M+5];

signed main(){
//	freopen("data.in", "w", stdout);
	mt19937 r(time(0));
	printf("%d\n", N);
	for (int i=1; i<=N; i++) 
		printf("%d ", rand()%V);
	putchar('\n');
	
	printf("%d\n", M);
	int type, c;
	for(int i=1; i<=M; i++){
		type = rand() % 3 + 1;
		if(type == 1){
			printf("%d ", type);
			printf("%d %d\n", rand()% N+1, rand()%V);
		}
		else if(type == 2){
			printf("%d ", type);
			printf("%d\n", rand()%V);
		}
		else{
			if(i == 1) {i--; continue;}
			printf("%d ", type);
			c = rand()%C+1;
			printf("%d ", c);
			for(int j=0; j < c; j++)
				printf("%d ", rand() % (i - 1) + 1);
			putchar('\n');
		}
	}
	
	printf("%d\n", Q);
	for(int i=1; i<=Q; i++){
		printf("%d ", rand()%M+1);
	}
	
	return 0;
}

