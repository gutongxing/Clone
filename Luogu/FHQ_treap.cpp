#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5+10;
struct node{
    int ls,rs,id,sz,pri;
}tree[MAXN];
#define lson tree[k].ls
#define rson tree[k].rs
void pushup(int k){
    tree[k].sz = tree[lson].sz+tree[rson].sz+1;
}
void split(int k,int c,int &x,int &y){
    if(!k){
        x = y = 0;
        return;
    }
    if(tree[k].id<=c){
        x = k;
        split(rson,c,rson,y);
    }else{
        y = k;
        split(lson,c,x,lson);
   }
    pushup(k);
}
void split_rank(int k,int c,int &x,int &y){
    if(!k){
        x = y = 0;
        return;
    }
    if(tree[lson].sz+1<=c){
        x = k;
        split_rank(rson,c-tree[lson].sz-1,rson,y);
    }else{
        y = k;
        split_rank(lson,c,x,lson);
   }
    pushup(k);
}
int merge(int x,int y){
    if(!x||!y) return x|y;
    if(tree[x].pri<tree[y].pri){
        tree[x].rs = merge(tree[x].rs,y);
        pushup(x);
        return x;
    }else{
        tree[y].ls = merge(x,tree[y].ls);
        pushup(y);
        return y;
    }
}
mt19937 rd;
int sum,root;
int New_node(int x){
    sum++;
    tree[sum].pri = rd();
    tree[sum].id = x;
    tree[sum].sz = 1;
    return sum;
}
void Insert(int x){
    int lroot,rroot;
    split(root,x,lroot,rroot);
    root = merge(merge(lroot,New_node(x)),rroot);
}
void Delete(int x){
    int lroot,temp,rroot;
    split(root,x,lroot,rroot);
    split(lroot,x-1,lroot,temp);
    temp = merge(tree[temp].ls,tree[temp].rs);
    root = merge(merge(lroot,temp),rroot);
}
int kth(int k){
    int lroot,rroot,temp;
    split_rank(root,k,lroot,rroot);
    split_rank(lroot,k-1,lroot,temp);
    int ans = tree[temp].id;
    root = merge(merge(lroot,temp),rroot);
    return ans;
}
int Rank(int x){
    int lroot,rroot,ans;
    split(root,x-1,lroot,rroot);
    ans = tree[lroot].sz;
    root = merge(lroot,rroot);
    return ans;
}
int Pre(int x){
    int lroot,rroot,ans;
    split(root,x-1,lroot,rroot);
    int now = lroot;
    while(tree[now].rs) now = tree[now].rs;
    ans = tree[now].id;
    root = merge(lroot,rroot);
    return ans;
}
int Suc(int x){
    int lroot,rroot,ans;
    split(root,x,lroot,rroot);
    int now = rroot;
    while(tree[now].ls) now = tree[now].ls;
    ans = tree[now].id;
    root = merge(lroot,rroot);
    return ans;
}
signed main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int opt,x;
        scanf("%d%d",&opt,&x);
        if(x==84185){
            int y = 0;
        }
        switch(opt){
        case 1:{
            Insert(x);
            break;
        }
        case 2:{
            Delete(x);
            break;
        }
        case 3:{
            printf("%d\n",Rank(x)+1);
			break;
        }
        case 4:{
            printf("%d\n",kth(x));
			break;
        }
        case 5:{
            printf("%d\n",Pre(x));
			break;
        }
        case 6:{
            printf("%d\n",Suc(x));
			break;
        }
        }
    }
    return 0;
}
