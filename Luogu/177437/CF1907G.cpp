#include<bits/stdc++.h>
using namespace std;
#pragma G++ optimize(1)
#pragma G++ optimize(2)
#pragma G++ optimize(3)
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
void write(char x){
    putchar(x);
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
const int MAXN = 2e5+10;
int T,n,loop1[MAXN],loop2[MAXN],floop1[MAXN],floop2[MAXN];
//graph
struct graph{
    struct EDGE{int x,y,nxt,from;}edge[MAXN];
    int h[MAXN],cnt;
    void new_edge(int x,int y,int from){
        edge[++cnt] = {x,y,h[x],from};
        h[x] = cnt;
    }
}v,tree;
//Topo
int inde[MAXN];
bitset<MAXN> loop,is;
void Topo(){
    queue<int> topo;
    for(int i = 1;i<=n;i++) if(!inde[i]) topo.push(i);
    while(!topo.empty()){
		int tmp = topo.front();topo.pop();loop[tmp] = 0;
		for(int pppi=v.h[tmp],i;pppi,i=v.edge[pppi].y;pppi=v.edge[pppi].nxt) 
			if(!(--inde[i])) topo.push(i);
	}
//	cout << loop[1] << " " << loop[2] << " " << loop[3] << " " << loop[4] << " " << loop[5] << endl;
}
void new_graph(){
    for(int i = 1;i<=n;i++){
        for(int pppj = v.h[i];pppj;pppj = v.edge[pppj].nxt){
            int j = v.edge[pppj].y;
            if(!loop[j]) tree.new_edge(i,j,v.edge[pppj].from);
            else if(!loop1[i]) loop1[i]=j,floop1[i]=v.edge[pppj].from;
            else loop2[i] = j,floop2[i]=v.edge[pppj].from;
        }
    }
}
//DP
vector<int> ans;
int dfs(int k,int fath){
    int sum = is[k];
    for(int pppp = tree.h[k];pppp;pppp = tree.edge[pppp].nxt){
        int i = tree.edge[pppp].y;
        if(i==fath) continue;
        int p = dfs(i,k);
        sum += p;
        if(p) ans.push_back(tree.edge[pppp].from);
    }
    return sum%2;
}
bitset<MAXN> vis;
int dfs_loop(int k,int from,int fath,vector<int> &ans){
    int sum = is[k];vis[k] = 1;int q = 0;
	if(k==from) return sum;
    if(loop1[k]!=fath){
		q++;
        int p = dfs_loop(loop1[k],from,k,ans);
        sum += p;
        if(p) ans.push_back(floop1[k]);
    }else if(loop2[k]!=fath){
		q++;
        int p = dfs_loop(loop2[k],from,k,ans);
        sum += p;
        if(p) ans.push_back(floop2[k]);
    }
	if(!q){
		int p = dfs_loop(loop1[k],from,k,ans);
		sum += p;
		if(p) ans.push_back(floop1[k]);
	}
    return sum%2;
}
//Normal
void clear(){
    vis.reset();loop.reset();ans.clear();
    v.cnt = tree.cnt = 0;
    for(int i = 1;i<=n;i++){
		v.h[i] = 0;tree.h[i] = 0;
        inde[i] = 0;
        loop[i] = 1;
        loop1[i] = 0;
        loop2[i] = 0;
		floop1[i] = 0;
		floop2[i] = 0;
    }
}
signed main(){
    read(T);
    while(T--){
//		if(T==9888){
//			cin >> n;cout << n;
//			string x;
//			cin >> x;cout << x << endl;
//			for(int i = 1;i<=n;i++){
//				int x;
//				cin >>x ;
//				cout << x << " ";
//			}
//			return 0;
//		}
		read(n);
		clear();
        for(int i = 1;i<=n;i++){
            char k;
            read(k);
            is.set(i,k-'0');
        }
        for(int i = 1;i<=n;i++){
            int x;
            read(x);
			inde[x]++;
            v.new_edge(i,x,i);
            v.new_edge(x,i,i);
        }
        Topo();new_graph();
//		for(int pppp = tree.h[9],i;pppp,i=tree.edge[pppp].y;pppp=tree.edge[pppp].nxt) cout << i << endl;
        for(int i = 1;i<=n;i++){
            if(loop[i]){
                int sum = is[i];
                for(int pppj=tree.h[i],j;pppj,j=tree.edge[pppj].y;pppj=tree.edge[pppj].nxt){
                    int p = dfs(j,i);
                    sum += p;
                    if(p) ans.push_back(tree.edge[pppj].from);
                }
                is.set(i,sum%2);
            }
        }
		bool fg = 1;
        for(int i = 1;i<=n;i++){
            if(loop[i]&&!vis[i]&&is[i]){
                vector<int> ans1,ans2;
                int k = dfs_loop(loop1[i],i,i,ans1);
                dfs_loop(loop2[i],i,i,ans2);
				if(k&1) fg  = 0;
                if(ans1.size()>ans2.size()) swap(ans1,ans2);
                for(int i:ans1) ans.push_back(i);
            }
        }
		if(fg){
        write((int)ans.size());write('\n');
        for(int i:ans) write(i),write(' ');
        write('\n');
		}else puts("-1");
    }
    return 0;
}
