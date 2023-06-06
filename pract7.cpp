#include <iostream>
using namespace std;
class student{
    int arr[10][10];
    int v_array[10];
    int v,e,w;
    int lowvertex,highvertex;
    public:
    void create();
    void min();
};
void student::create(){
    cout<<"enter the no of vertices"<<endl;
    cin>>v;
    cout<<"enter the no of edges"<<endl;
    cin>>e;
    for(int i=0;i<v;i++){
        v_array[i]=0;
    }
    for(int i=0;i<v;i++){
        cout<<v_array[i];
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            arr[i][j]=999;
        }
    }
    cout<<"ajacency matrix"<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<arr[i][j];
        }
    }
    for(int i=0;i<e;i++){
        cout<<"enter the nodes at end"<<endl;
        cin>>highvertex;
        cin>>lowvertex;
        cout<<"enter the weight"<<endl;
        cin>>w;
        arr[lowvertex][highvertex]=arr[highvertex][lowvertex]=w;
    }
}
void student::min(){
    int count,q=0,p=0,total=0,min;
    v_array[0]=1;
    for(int count=0;count<v-1;count++){
        min=999;
        for(int i=0;i<v;i++){
            if(v_array[i]==1){
                for(int j=0;j<v;j++){
                    if(v_array[j]!=1){
                        if(min>arr[i][j]){
                            min=arr[i][j];
                            p=i;
                            q=j;
                        }
                    }
                }

            }

        }
        v_array[p]=1;
        v_array[q]=1;
        total=total+min;

        cout<<"min"<<min;
    }
    cout<<"cost"<<total;
}
int main(){
    student obj1;
    obj1.create();
    obj1.min();
    return 0;
}