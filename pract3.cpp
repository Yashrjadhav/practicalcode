#include <iostream>
using namespace std;
struct node{
    char label[20];
    int ch_count;
    struct node*child[20];
}*root;
class book{
    public:
    book(){
        root=NULL;
    }
    void create();
    void display(node*r1);
};
void book::create(){
    int tch;
    root =new node;
    cout<<"enter the name of book"<<endl;
    cin>>root->label;
    cout<<"enter the total no of chapter"<<endl;
    cin>>tch;
    root->ch_count=tch;
    for(int i=0;i<tch;i++){
        root->child[i]=new node;
        cout<<"enter the name of chapter"<<i+1<<endl;
        cin>>root->child[i]->label;
        cout<<"enter the no of section in chap"<<i+1<<endl;
        cin>>root->child[i]->ch_count;
        for(int j=0;j<root->child[i]->ch_count;j++){
            root->child[i]->child[j]=new node;
            cout<<"enter the name of section"<<j+1<<endl;
            cin>>root->child[i]->child[j]->label;
            cout<<"enter the no of sub sections in section"<<j+1<<endl;
            cin>>root->child[i]->child[j]->ch_count;
            for(int k=0;k<root->child[i]->child[j]->ch_count;k++){
                root->child[i]->child[j]->child[k]=new node;
                cout<<"enter the name of subsection"<<endl;
                cin>>root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}
void book::display(node*r1){
    int tch=r1->ch_count;
    cout<<"book heirchy"<<endl;
    cout<<r1->label;
    for(int i=0;i<tch;i++){
        cout<<"chapters"<<endl;
        cout<<root->child[i]->label;
        for(int j=0;j<r1->child[i]->ch_count;j++){
            cout<<"section"<<endl;
            cout<<r1->child[i]->child[j]->label;
            for(int k=0;k<r1->child[i]->child[j]->ch_count;k++){
                cout<<"sub section"<<endl;
                cout<<r1->child[i]->child[j]->child[k]->label;

            }
        }
    }
}
int main(){
    book obj;
    obj.create();
    obj.display(root);
}