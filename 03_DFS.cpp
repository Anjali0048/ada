#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <list>

using namespace std;

void dfs(int s, vector<vector<int>> g, vector<bool> &vis){
    cout<<s<<" ";
    vis[s] = true;
    
    for(int i=0; i<g[s].size(); i++){
        if(!vis[g[s][i]])
            dfs(g[s][i], g, vis);
    }
}

int main()
{   
        int N, E;
        cin>>N>>E;
        
        vector<vector<int>> g(N);
        vector<bool> vis(N,0);
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0,g,vis);
        
        cout<<endl;

}