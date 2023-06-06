#include <iostream>
#include <stdlib.h>
using namespace std;
int cost[10][10],que[10],rear,front,visited[10],visit[10],i,j,k,v1,v;
int stck[10],top,visited1[10],visit1[10];
int main(){
    int e;
    cout<<"enter no of vertices"<<endl;
    cin>>v;
    cout<<"enter no of edges"<<endl;
    cin>>e;
    for(int k=1;k<=e;k++){
        cout<<"enter the nodes of edges"<<endl;
        cin>>i>>j;
        cost[i][j]=1;
        cost[j][i]=1;
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<cost[i][j]<<" ";
        }cout<<endl;
    }
    cout<<"enter initial vertex"<<endl;
    cin>>v1;
    cout<<"bfs traversal"<<endl;
    cout<<v1<<endl;
    visited[v1]=1;
    k=1;
    while(k<v){
        for(int j=1;j<=v;j++)
            if(cost[v1][j]!=0 && visited[j]!=1 && visit[j]!=1){
                visit[j]=1;
                que[rear++]=j;
            }
        v1=que[front++];
        cout<<v1<<" ";
        k++;
        visit[v1]=0;
        visited[v1]=1;
    }
    cout<<"enter initial vertex"<<endl;
    cin>>v1;
    cout<<"dfs traversal"<<endl;
    cout<<v1<<endl;
    visited1[v1]=1;
    k=1;
    while(k<v){
        for(int j=v;j>=1;j--){
            if(cost[v1][j]!=0 && visited1[j]!=1 && visit1[j]!=1){
                visit1[j]=1;
                stck[top]=j;
                top++;
            }
        }
        v1=stck[--top];
        cout<<v1<<endl;
        k++;
        visit1[v1]=0;
        visited1[v1]=1;
    }

}