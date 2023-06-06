#include<bits/stdc++.h>
using namespace std;

struct node{
    char data;
    node *left, *right;
};

class Stack{
        node *data[30];
        int top;
    public:
        Stack(){
            top = -1;
        }
        int empty(){
            if(top==-1)
                return 1;
            return 0;
        }
        void push(node *p){
            data[++top]=p;
        }
        node *pop(){
            return(data[top--]);
        }
};

class tree
{
        char prefix[20];
    public:
        node *top;
        void express(char []);
        void display(node *);
        void nonRecPostorder(node *);
        void del(node *);
};


void tree::express(char prefix[]){
    char c;
    Stack s;
    node *t1, *t2;
    int len = strlen(prefix);
    for(int i=len-1;i>=0;i--){
        top = new node;
        top->left = NULL;
        top->right= NULL;
        if(isalpha(prefix[i])){
            top->data = prefix[i];
            s.push(top);
        }
        else if(prefix[i]=='+' || prefix[i]=='-' || prefix[i]=='*' || prefix[i]=='/'){
            t2 = s.pop();
            t1 = s.pop();

            top->data = prefix[i];
            top->left = t2;
            top->right = t1;
            s.push(top);
        }
    }
    top = s.pop();
}

void tree::display(node *r){
    if(r!=NULL){
        cout<<r->data;
        display(r->left);
        display(r->right);
    }
}

void tree::nonRecPostorder(node *top){
    Stack s1, s2;
    node *t = top;
    cout<<endl;
    s1.push(t);
    while (!s1.empty()){
        t = s1.pop();
        s2.push(t);
        if(t->left!= NULL)
            s1.push(t->left);
        if(t->right!=NULL)
            s1.push(t->right);
    }
    while (!s2.empty()){
        top = s2.pop();
        cout<<top->data;
    }
}

void tree::del(node *n){
    if(n==NULL)
        return;
    del(n->left);
    del(n->right);
    cout<<"Deleting the node"<<n->data;
    free(n);
}

int main()
{
    char exp[20];
    tree t;

    cout<<"Enter the prefix Expression:";
    cin>>exp;

    t.express(exp);
    t.nonRecPostorder(t.top);
    t.del(t.top);
    return 0;
}
