#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    int E;

    public:
    vector<pair<int,pair<int,int> > > edges;
    void addEdge(int s,int d,int w){
        edges.push_back({w, {s,d} });
    }

    Graph(int v,int e){
        V=v;
        E=e;
        //edges.assign(e,pair<pair<int,int>,int>());
    }
    void Kruskal(Graph&,vector<vector<int> >&);
};

bool Cycle_DFS1(int v,vector<vector<int> > &adl,vector<bool> &visited,int parent){
    visited[v]=true;
    for(int i=0;i<adl[v].size();i++){
        if(!visited[adl[v][i]]){
            if(Cycle_DFS1(adl[v][i],adl,visited,v)){
                return true;
            }
        }
        else if(adl[v][i]!=parent){
            return true;
        }
    }
return false;
}

bool Cycle(int v,vector<vector<int> > &adl){
    vector<bool> visited(v,false);
    for(int i=1;i<=v;i++){
        if(!visited[i]){
            if(Cycle_DFS1(i,adl,visited,-1)){
                return true;
            }
        }
    }
return false;
}

void Graph::Kruskal(Graph &result,vector<vector<int> > &adl){
    sort(this->edges.begin(),this->edges.end());
    int wt=0;
    vector<pair<int,pair<int,int> > >:: iterator i;
    for(i=this->edges.begin();i!=this->edges.end();i++){

        int s= i->second.first;
        int d= i->second.second;
        int w= i->first;

        result.addEdge(s,d,w);

        adl[s].push_back(d);
        adl[d].push_back(s);

        if(Cycle(V,adl)){
            adl[s].pop_back();
            adl[d].pop_back();
            result.edges.pop_back();
            continue;
        }
        wt+=w;
    }
cout<<"\nMST= "<<wt<<'\n'<<endl;
}

int main(){
    int v,e;
    cout<<"Enter number of Vertex and Edges: ";
    cin>>v>>e;
    Graph g(v,e);
    cout<<"Enter Edges (ex: v1 v2 weight) :\n";
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y;
        cin>>w;
        g.addEdge(x,y,w);
        //cout<<g.edges[i].first.first<<' ';
    }
    vector<vector<int> > adl(v+1);
    Graph result(v,v-1);
    g.Kruskal(result,adl);
    vector<pair<int,pair<int,int> > > :: iterator i;
    for(i=result.edges.begin();i!=result.edges.end();i++){
        cout<<i->second.first<<"----"<<i->second.second<<"==="<<i->first<<'\n';
    }
return 0;
}
