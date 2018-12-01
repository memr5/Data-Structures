#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
class Graph{

    int V;
    int E;

    public:

    vector<pair<int,int> > *adl;

    Graph(int v,int e){
        V=v;
        E=e;
        adl = new vector<pair<int,int> >[v+1];
    }

    void addEdge(int s,int d,int w){
            adl[s].push_back({d,w});
            adl[d].push_back({s,w});
    }

    void Prims_MST();

    void print_MST(vector<int>);
};

void Graph::print_MST(vector<int> parent){
    cout<<"\nPrims_MST:\n\n";
    for(int i=2;i<=V;i++){
        cout<<parent[i]<<"----"<<i<<endl;
    }
}

void Graph::Prims_MST(){

    vector<pair<int,int> > pq;
    vector<bool> visited(V+1,false);
    vector<int> parent(V+1,-1);
    vector<int> key(V+1,INF);
    int wt=0;
    pq.push_back({0,1});

    while(!pq.empty()){

        int u = pq.back().second;
        wt+=pq.back().first;
        pq.pop_back();
        visited[u]=true;

        for(int i=0;i<adl[u].size();i++){
            int w = adl[u][i].second;
            if( !visited[ adl[u][i].first ] && key[adl[u][i].first] > w ){
                parent[adl[u][i].first]=u;
                key[adl[u][i].first]=w;
                pq.push_back({w,adl[u][i].first});
                sort(pq.begin(),pq.end(),greater<pair<int,int> >());
            }
        }
    }
    cout<<"Weight= "<<wt<<endl;
    print_MST(parent);
}

int main(){
    int v,e;
    cout<<"\nEnter Number of Vertex and Edges: ";
    cin>>v>>e;
    Graph g(v,e);
    cout<<"Enter Edges (ex: v1 v2 w):\n";
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        g.addEdge(s,d,w);
    }
    g.Prims_MST();
return 0;
}
