class Solution {
public:
    unordered_map<int,vector<int>> hash;
    
    void dfs(int node,unordered_set<int> &visited){
        if(visited.find(node)!=visited.end())  return;
        visited.insert(node);
        for(int i:hash[node]){
            dfs(i,visited);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        for(auto edge:edges){
            hash[edge[0]].push_back(edge[1]);
            hash[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        int count=1;

        for(int i=0;i<n;i++){
            if(visited.find(i)!=visited.end())   continue;

            dfs(i,visited);

            if(visited.size()<n){
                count++;
            }
        }

        return count;
    }
};
