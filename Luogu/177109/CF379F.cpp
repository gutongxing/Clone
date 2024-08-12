#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+10;
const int LOGN = log2(MAXN)+2;
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
void read(char &x){
    x = getchar();
    while(x==' '||x=='\n'||x=='\r') x = getchar();
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
int A,B,q;
//LCA
int LCA_ST[MAXN][LOGN],LCA_dep[MAXN];
int LCA_jump(int k,int dep){
    int tmp = 0;
    while(dep){
        if(dep&1){
            k = LCA_ST[k][tmp];
        }
        tmp++;
        dep>>=1;
    }
    return k;
}
int LCA(int x,int y){
    if(LCA_dep[x]<LCA_dep[y]) swap(x,y);
    x = LCA_jump(x,LCA_dep[x]-LCA_dep[y]);
    if(x==y) return x;
    for(int i = LOGN-1;i>=0;i--){
        if(LCA_ST[x][i]!=LCA_ST[y][i]){
            x = LCA_ST[x][i];
            y = LCA_ST[y][i];
        }
    }
    return LCA_ST[x][0];
}
int cnt=4,cet;
void New(int u){
    LCA_ST[++cnt][0] = u;
    LCA_dep[cnt] = LCA_dep[u]+1;
    for(int j = 1;j<LOGN;j++){
        LCA_ST[cnt][j] = LCA_ST[LCA_ST[cnt][j-1]][j-1];
    }
    int lca_a = LCA(A,cnt);
    int lca_b = LCA(B,cnt);
    int dis_a = LCA_dep[A]+LCA_dep[u]-2*LCA_dep[lca_a]+1;
    int dis_b = LCA_dep[B]+LCA_dep[u]-2*LCA_dep[lca_b]+1;
    if(dis_a>cet&&dis_a>=dis_b){
        cet = dis_a;
        B = cnt;
    }else if(dis_b>cet){
        cet = dis_b;
        A = cnt;
    }
}
signed main(){
    LCA_ST[2][0] = 1;LCA_dep[2] = 1;
    LCA_ST[3][0] = 1;LCA_dep[3] = 1;
    LCA_ST[4][0] = 1;LCA_dep[4] = 1;
    cet = 1;
    A = 2;B = 3;
    read(q);
    while(q--){
        int u;
        read(u);
        New(u);New(u);
        write(cet);
        putchar('\n');
    }
    return 0;
}