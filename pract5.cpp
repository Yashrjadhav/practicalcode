#include <iostream>
#include <string.h>
using namespace std;
typedef struct node{
    char k[20];
    char m[20];
    class node *left;
    class node *right;
}node;
class dict{
    public:
    node *root;
    public:
    void create();
    void insert(node *root,node*temp);
    void display(node *root);
    int search(node*root,char k[20]);
};
void dict::create(){
    int ch;
    class node* temp;
    do{
    temp=new node;
    cout<<"enter the keyword"<<endl;
    cin>>temp->k;
    cout<<"enter the meaning"<<endl;
    cin>>temp->m;
    temp->right=NULL;
    temp->left=NULL;
    if(root==NULL){
        root=temp;
    }
    else{
        insert(root,temp);
    }
    cout<<"continue?"<<endl;
    cin>>ch;
    }while(ch==1);
}
void dict::insert(node*root,node*temp){
    if(strcmp(temp->k,root->k)<0){
        if(root->left==NULL){
            root->left=temp;
        }
        else{
            insert(root->left,temp);
        }
    }
    else{
        if(root->right==NULL){
            root->right=temp;
        }
        else{
            insert(root->right,temp);
        }
    }
}
void dict:: display(node*root){
    if(root!=NULL){
        display(root->left);
        cout<<"keyword"<<root->k;
        cout<<"meaning"<<root->m;
        display(root->right);
    }
}
int dict::search(node*root,char k[20]){
    int c=0;
    while(root!=NULL){
        c++;
        if(strcmp(k,root->k)==0){
            cout<<"no of comparison"<<c<<endl;
            return 1;
            
        }
        if(strcmp(k,root->k)<0){
            root=root->left;
            
        }
        if(strcmp(k,root->k)>0){
            root=root->right;
            
        }
    }
    return -1;
}
int main(){
    dict obj;
    obj.root=NULL;
    obj.create();
    obj.display(obj.root);
    cout<<"enter the keyword to search"<<endl;
    char k[20];
    cin>>k;
    if((obj.search(obj.root,k))==1){
        cout<<"keyword found"<<endl;
    }
    else{
        cout<<"keyword not found"<<endl;
    }
}
