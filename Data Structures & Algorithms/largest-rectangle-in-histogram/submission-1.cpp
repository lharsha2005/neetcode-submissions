class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;
        stack<pair<int,int>> stk;
        int n=heights.size();

        for(int i=0;i<n;i++){
            if(stk.empty())     stk.push({i,heights[i]});

            if(heights[i]<stk.top().second){
                int left;
                while(!stk.empty() && heights[i]<stk.top().second){
                    left=stk.top().first;
                    int area=(i-left)*stk.top().second;
                    maxArea=max(area,maxArea);
                    printf("%d ",maxArea);
                    stk.pop();
                }
                stk.push({left,heights[i]});
            }else{
                stk.push({i,heights[i]});
            }
        }

        while(!stk.empty()){
            int area=(n-stk.top().first)*stk.top().second;
            maxArea=max(area,maxArea);
            stk.pop();
        }

        return maxArea;
    }
};
