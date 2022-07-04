#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;


class node{
    public:
    node *lchild;
    node *rchild;
    int data;
};
node *root = nullptr;
void insert(int key){
    stack<node *> stack;
    node *p = root ;
    if(p==nullptr){
        node *ptr = new node  ;
        root = ptr ;
        root->data = key;
        root->lchild = nullptr ;
        root->rchild = nullptr ;
    }
    else { bool check_duplicate = false ;

     while (p!=nullptr)
     {   if(p!=nullptr)stack.push(p); 
         if(key==p->data)return;
       if(key>p->data)p=p->rchild;
      else  if(key<p->data) p=p->lchild;
     
        
     }
   node *ptr = new node ;
     ptr->lchild = ptr->rchild = nullptr ;
     ptr->data = key ;
     node *qtr = stack.top();
     if(key>qtr->data)qtr->rchild = ptr;
     else if(key<qtr->data)qtr->lchild = ptr;
      
    
    }
}
void inorder_transversal(node *ptr){
    if(ptr){
        inorder_transversal(ptr->lchild);
        cout<<ptr->data<<" ";
        inorder_transversal(ptr->rchild);
    }
}
void search_karo(int value){
    /* tc = n*log(n) */
 node *ptr = root ;
 if(ptr==nullptr){
    cout<<"No such value exist cuz tree is not created yet"<<endl;
 }
 else {
    while(ptr!=nullptr){
           if(value = ptr->data){cout<<"value found :)"<<endl; break;}
        if(value>ptr->data)ptr=ptr->rchild;
        else if(value<ptr->data)ptr=ptr->lchild;
   
    }
    if(ptr==nullptr)cout<<"value not found :("<<endl;
 }
}