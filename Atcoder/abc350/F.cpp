#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+10;
const int INF = 0x3f3f3f3f;
//FHQ_treap
int root,tot;
struct FHQ_treap{
	int lson,rson,sum,add;
	int priority,maxn = -INF;
	bool turn;
	char data;
}tree[MAXN];
int New_Node(char x){
	++tot;
	tree[tot].data = x;
	tree[tot].priority = (long long)rand()*rand()%(1<<30);
	tree[tot].sum++;
	return tot;
}
void pushup(int x){
	tree[x].sum = tree[tree[x].lson].sum+tree[tree[x].rson].sum+1;
}
void pushdown(int x){
	if(tree[x].turn){
		tree[tree[x].lson].turn^=1;
		tree[tree[x].rson].turn^=1;
		if('a'<=tree[tree[x].lson].data&&tree[tree[x].lson].data<='z') 
		tree[tree[x].lson].data -= ' ';
		else tree[tree[x].lson].data += ' ';
		if('a'<=tree[tree[x].rson].data&&tree[tree[x].rson].data<='z') 
		tree[tree[x].rson].data -= ' ';
		else tree[tree[x].rson].data += ' ';
		swap(tree[tree[x].lson].lson,tree[tree[x].lson].rson);
		swap(tree[tree[x].rson].lson,tree[tree[x].rson].rson);
		tree[x].turn^=1;
	}
	tree[0].lson=tree[0].rson=tree[0].sum=tree[0].add=tree[0].data=tree[0].priority=tree[0].maxn=tree[0].turn = 0;
	tree[0].maxn = -INF;
}
void split_value(int x,char k,int &l,int &r){
	if(!x){
		l = r = 0;
		return;
	}
	pushdown(x);
	if(tree[x].data<=k){
		l = x;
		split_value(tree[x].rson,k,tree[x].rson,r);
	}else{
		r = x;
		split_value(tree[x].lson,k,l,tree[x].lson);
	}
	pushup(x);
}
void split_Rank(int x,char k,int &l,int &r){
	if(!x){
		l = r = 0;
		return;
	}
	pushdown(x);
	int ln = tree[tree[x].lson].sum+1;
	if(ln-1<k){
		l = x;
		split_Rank(tree[x].rson,k-ln,tree[x].rson,r);
	}else{
		r = x;
		split_Rank(tree[x].lson,k,l,tree[x].lson);
	}
	pushup(x);
}
int merge(int l,int r){
	if(!l||!r) return l|r;
	pushdown(l);
	pushdown(r);
	if(tree[l].priority<tree[r].priority){
		tree[l].rson = merge(tree[l].rson,r);
		pushup(l);
		return l;
	}else{
		tree[r].lson = merge(l,tree[r].lson);
		pushup(r);
		return r;
	}
}
void insert(char x){
	root = merge(root,New_Node(x));
}
void Show(int &root){
	if(!root) return;
	int lroot,rroot,temp;
	pushdown(root);
	Show(tree[root].lson);
	printf("%c",tree[root].data);
	Show(tree[root].rson);
}
void modify_turn(int l,int r){
	if(r<l) return;
	int lroot,temp,rroot;
	split_Rank(root,l-1,lroot,rroot);
	split_Rank(rroot,r-l+1,temp,rroot);
	tree[temp].turn^=1;
	swap(tree[temp].lson,tree[temp].rson);
	if('a'<=tree[temp].data&&tree[temp].data<='z') 
	tree[temp].data -= ' ';else tree[temp].data += ' ';
	root = merge(merge(lroot,temp),rroot);
}
//Other
int n,m,ans;
char a[MAXN];
signed main(){
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	srand(time(NULL));
	scanf("%s",a+1);
	stack<int> st;
	int si = strlen(a+1);
	for(int i = 1;i<=si;i++){
		if(a[i]!='('&&a[i]!=')') insert(a[i]);
	}
//	system("pause");
	int tot = 0;
//	Show(root);puts("");
	for(int i = 1;i<=si;i++){
		if(a[i]=='(') st.push(tot+1);
		else if(a[i]==')'){
			modify_turn(st.top(),tot);st.pop();
		}else tot++;
//		Show(root);puts("");
	}
	Show(root); 
	return 0;
}
/*
5 3
1 3
1 2
2 4

1 2 3 4 5
3 2 1 4 5
2 3 1 4 5
2 4 1 3 5
*/
