#include<bits/stdc++.h>
using namespace std;

bool Cycle_DFS(int v,vector<vector<int> > adl,vector<bool> &visited,int parent){
    if(v==1){
        visited[v]=true;
    }

    for(int i=0;i<adl[v].size();i++){
        if(!visited[adl[v][i]]){
            visited[adl[v][i]]=true;
            if( Cycle_DFS(adl[v][i],adl,visited,v) ){
                return true;
            }
        }
        else if(adl[v][i]!=parent){
            return true;
        }
    }
return false;
}

int main(){
    int n;
    cout<<"Enter number of Vertex: ";
    cin>>n;
    vector<vector<int> > adl(n+1);
    vector<bool> visited(n+1,false);
    int e;
    cout<<"Enter number of Edges: ";
    cin>>e;
    cout<<"Enter Edges:\n";

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adl[x].push_back(y);
        adl[y].push_back(x);
    }

    bool flag=false;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
           if(Cycle_DFS(i,adl,visited,-1)){
                flag=true;
                break;
           }
        }
    }
    if(flag){
        cout<<"Cycle Present!"<<endl;
    }
    else{
        cout<<"Cycle not Present"<<endl;
    }
return 0;
}
