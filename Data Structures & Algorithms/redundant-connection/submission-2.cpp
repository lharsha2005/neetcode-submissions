class Solution {
public:
    unordered_map<int,vector<int>> hash;

    bool dfs(int node,vector<int> &visited,int par){
        if(visited[node]==1)    return true;
        visited[node]=1;

        for(int i:hash[node]){
            if(i==par)  continue;
            if(dfs(i,visited,node))     return true;
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(auto edge:edges){
            hash[edge[0]].push_back(edge[1]);
            hash[edge[1]].push_back(edge[0]);

            vector<int> visited(edges.size()+1,0);
            if(dfs(edge[0],visited,-1)){
                return {edge[0],edge[1]};
            }
        }

        return {};
    }
};
