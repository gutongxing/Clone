#include<bits/stdc++.h>
#pragma G++ optimize(1)
#pragma G++ optimize(2)
#pragma G++ optimize(3)
#pragma G++ optimize("Ofast")
using namespace std;
int n;
int sum[120][120][120][3];
struct coord{
	int x,y,z;
};
struct node{
	coord cube1,cube2;
}a[100010];
set<int> ans[100005];
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
	if(k<0) write('-');
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
int link(int &x,int y){
	if(x!=0){
		ans[x].insert(y);
		ans[y].insert(x);
//cout << "----------" << endl << x << endl; 
	}else{
		x = y; 
	}
}
signed main(){
	read(n);
	for(int i = 1;i<=n;i++){
		read(a[i].cube1.x);
		read(a[i].cube1.y);
		read(a[i].cube1.z);
		read(a[i].cube2.x);
		read(a[i].cube2.y);
		read(a[i].cube2.z);
		for(int x = a[i].cube1.x;x<a[i].cube2.x;x++){
			for(int y = a[i].cube1.y;y<a[i].cube2.y;y++){
				link(sum[x][y][a[i].cube1.z][0],i);
				link(sum[x][y][a[i].cube2.z][0],i);
			}
		}
		for(int y = a[i].cube1.y;y<a[i].cube2.y;y++){
			for(int z = a[i].cube1.z;z<a[i].cube2.z;z++){
				link(sum[a[i].cube1.x][y][z][1],i);
				link(sum[a[i].cube2.x][y][z][1],i);
			}
		}
		for(int x = a[i].cube1.x;x<a[i].cube2.x;x++){
			for(int z = a[i].cube1.z;z<a[i].cube2.z;z++){
				link(sum[x][a[i].cube1.y][z][2],i);
				link(sum[x][a[i].cube2.y][z][2],i);
			}
		}
	}
	for(int i = 1;i<=n;i++){
		write(ans[i].size());putchar('\n');
	}
	return 0;
}

