#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cout<<"Enter number of vertices : ";
    cin>>n;
    vector<vector<int> > adl(n+1);
    queue<int> q;
    vector<bool> visited(n+1,false);
    cout<<"Enter Number of Edges: ";
    cin>>e;
    cout<<"Enter Edges (ex: v1 v2) :\n ";
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adl[x].push_back(y);
        adl[y].push_back(x);
    }

    q.push(1);
    visited[1]=true;
    cout<<"BFS: ";
    while(!q.empty()){
        int x = q.front();
        cout<<x<<' ';
        for(int i=0;i<adl[x].size();i++){
            if(!visited[ adl[x][i] ]){
                q.push(adl[x][i]);
                visited[adl[x][i]]=true;
            }
        }
        q.pop();
    }
return 0;
}
