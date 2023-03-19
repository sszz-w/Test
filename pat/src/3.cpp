#include <bits/stdc++.h>
using namespace std;
const int maxn=50000;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
vector<int> pre,in,post;
node* create(int postL,int postR,int inL,int inR){
    if(postL>postR) return nullptr;
    node* root=new node;
    root->data=post[postR];
    int k;
    for(k=inL;k<=inR;k++){
        if(in[k]==post[postR]) break;
    }
    int numLeft=k-inL;
    root->lchild=create(postL,postL+numLeft-1,inL,k-1);
    root->rchild=create(postL+numLeft,postR-1,k+1,inR);
    return root;
}
void preOrder(node* root){
    if(root==nullptr) return;
    pre.push_back(root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}
int main(){
    int n;
    cin>>n;
    in.resize(n);
    post.resize(n);
    for(int i=0;i<n;i++) cin>>post[i];
    for(int i=0;i<n;i++) cin>>in[i];
    node* root=create(0,n-1,0,n-1);
    preOrder(root);
    cout<<pre[n-1];
    return 0;
}