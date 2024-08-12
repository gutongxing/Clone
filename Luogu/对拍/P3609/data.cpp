#include<bits/stdc++.h>
using namespace std;
#define int long long 
int random(){
	return (unsigned)rand()*(unsigned)rand();
}
int random(int l,int r){
	return random()%(r-l+1)+l;
}
int n,m;
signed main(){
    struct _timeb T;
    _ftime(&T);
    srand(T.millitm);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    n = 5;
    m = 7;
    printf("%lld %lld\n",n,m); 
    for(int i = 1;i<=n;i++){
    	printf("%lld\n",random(1,1e9));
	}
    for(int i = 1;i<=m;i++){
    	int opt = random(0,3);
    	if(opt==0){
    		
		}if(opt<3){
    		printf("%lld %lld %lld\n",opt,random(1,n),random(1,n));
		}else{
			printf("3 %lld %lld\n",random(1,n),random(1,1e9));
		}
	}
	return 0;
}

