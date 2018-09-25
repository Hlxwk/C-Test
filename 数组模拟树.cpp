#include<stdio.h>
int lch[100],rch[100],
pre[100],inorder[100],sum=0,v[100];
int build(int,int,int,int);
void postOrder(int,int);
int main(){
    //freopen("input.txt","r",stdin);
    int n,i,x,c1=0,c2=0,stack[100],c=-1;
    for(scanf("%d",&n),i=0;i<2*n;i++){
        char in[100];
        scanf("%s",in);
        if(in[1]=='u') 
            scanf("%d",&x),
            pre[c1]=c1+1,stack[++c]=++c1,v[c1]=x;
        else inorder[c2++]=stack[c--];
    }
    int root=build(0,c1-1,0,c2-1);
    postOrder(root,n);
}
int build(int l1,int r1,int l2,int r2){
    if(l1>r1) return 0;
    int root=pre[l1],i,cnt=0;
    for(i=l2;inorder[i]!=root;cnt++,i++);
    lch[root]=build(l1+1,l1+cnt,l2,i-1);
    rch[root]=build(l1+cnt+1,r1,i+1,r2);
    return root;
}
void postOrder(int x,int n){
    if(!x) return;
    postOrder(lch[x],n);
    postOrder(rch[x],n);
    printf("%d",v[x]),sum++;
    if(sum-n) printf(" ");
    else printf("\n");
}
