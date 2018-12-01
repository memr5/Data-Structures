#include<bits/stdc++.h>
using namespace std;

void DFS(int v,vector<vector<int> > adl,vector<bool> &visited){

    for(int i=0;i<adl[v].size();i++){
        if(!visited[ adl[v][i] ]){
            visited[adl[v][i]]=true;
            cout<<adl[v][i]<<' ';
            DFS(adl[v][i],adl,visited);
        }
        /*else{
            cout<<"CYCLE DETECTED!!"<<endl;
            exit(0);
        }*/
    }
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

    cout<<"DFS: ";
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i]=true;
            cout<<i<<' ';
            DFS(i,adl,visited);
        }
    }
return 0;
}


