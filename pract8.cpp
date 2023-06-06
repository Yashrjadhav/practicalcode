#include <iostream>
using namespace std;
#define N 10
int q[N],p[N],w[10][10],c[10][10],r[10][10],j;
char idnt[7][10];
int find(int i,int j);
void print(int i,int j);
int main(){
    int n;
    cout<<"enter the no of identifiers"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"enter the elements"<<endl;
        cin>>idnt[i];
    }
    for(int i=1;i<=n;i++){
    cout<<"enter the  success prob"<<endl;
    cin>>p[i];
    }
    for(int i=0;i<=n;i++){
        cout<<"enter the failure prob"<<endl;
        cin>>q[i];
    }
    cout<<"weight\tcost\troot"<<endl;
    for(int i=0;i<=n;i++){
        w[i][i]=q[i];
        c[i][i]=r[i][i]=0;
        cout<<w[i][i]<<c[i][i]<<r[i][i]<<endl;
    }
    cout<<"weight\tcost\troot"<<endl;
    for(int i=0;i<n;i++){
    int j=i+1;
    w[i][j]=q[i]+p[j]+q[j];
    c[i][j]=w[i][j]+c[i][j-1]+c[j][j];
    r[i][j]=j;
    cout<<w[i][j]<<c[i][j]<<r[i][j]<<endl;
    }
    cout<<"weight\tcost\troot"<<endl;
    for(int m=2;m<=n;m++){
        for(int i=0;i<=n-m;i++){
            j=m+i;
            w[i][j]=w[i][j-1]+q[j]+p[j];
            int k=find(i,j);
            r[i][j]=k;
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
            cout<<w[i][j]<<c[i][j]<<r[i][j]<<endl;
        }
    }
    print(0,n);
    return 0;
}
int find(int i,int j){
    int min=2000,m,l;
    for(m=i+1;m<=j;m++){
        if((c[m][j]+c[i][m-1])<min){
            min=c[m][j]+c[i][m-1];
            l=m;
        }
    }
    return l;
}
void print(int i,int j){
    if(i<j){
    cout<<idnt[r[i][j]]<<endl;
    }
    else
    return;
    print(i,r[i][j]-1);
    print(r[i][j],i);
}