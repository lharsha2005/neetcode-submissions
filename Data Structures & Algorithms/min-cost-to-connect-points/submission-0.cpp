class Solution {
public:
    int cost(vector<int> p1,vector<int> p2){
        int t1=abs(p1[0]-p2[0]);
        int t2=abs(p1[1]-p2[1]);

        return (t1+t2);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_set<int> visit;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;

        minH.push({0,0});
        int ans=0;
        while(visit.size()<points.size()){
            auto curr=minH.top();
            minH.pop();
            int temp=curr.first;
            int i=curr.second;

            if(visit.count(i))  continue;

            ans+=temp;
            visit.insert(i);
            for(int j=0;j<points.size();j++){
                if(i==j)    continue;

                minH.push({cost(points[i],points[j]),j});
            }
        }

        return ans;
    }
};
