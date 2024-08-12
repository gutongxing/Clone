#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x = 0;int p = 1;char ch;
	do{
		ch = getchar();
		if(ch=='-') p = -1;
	}while(!isdigit(ch));
	while(isdigit(ch)){
		x*=10;
		x+=ch-'0';
		ch = getchar();
	}
	x*=p;
}
void write(int k){
	if(k<0) putchar('-');
	k = abs(k);
	stack<int> num;
	do{
		num.push(k%10);
		k/=10;
	}while(k);
	while(!num.empty()){
		putchar(num.top()+48);
        num.pop();
	}
}
void read(char x){
    do x = getchar();
    while(x=='\n'||x==' '||x=='\r');
}
// int read(char &x){
//     int cnt = 0;
//     char tmp = getchar();
//     while(tmp=='\n'||tmp==' '||tmp=='\r') tmp = getchar();

// }
int n,m,now,ans = 0x3f3f3f3f;
char a[20][20];
bitset<30> l[20];
signed main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%s",a[i]+1);
        for(int j = 1;j<=m;j++){
            if(a[i][j]=='o') l[i].flip(j);
        }
    }
    for(int i = 1;i<(1<<n);i++){
        int u = i;bitset<30> k;int sum = 0;
        while(u){
            int tmp = log2(u&-u)+1;
            k |= l[tmp];
            u -= u&-u;
            sum++;
        }
        if(k.count() == m){
            ans = min(ans,sum);
        }
    }
    write(ans);
    return 0;
}