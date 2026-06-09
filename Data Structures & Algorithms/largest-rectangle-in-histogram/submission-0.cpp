class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> area(heights.size());

        for(int i=0;i<heights.size();i++){
            int left=0;
            int right=0;
            if(i!=0){
                for(int j=i-1;j>=0;j--){
                    if(heights[j]>=heights[i])  left++;
                    else break;
                }
            }
            if(i!=heights.size()-1){
                for(int j=i+1;j<heights.size();j++){
                    if(heights[j]>=heights[i])  right++;
                    else break;
                }
            }

            printf("%d %d|",left,right);
            area[i]=(left+right+1)*heights[i];
        }

        int m=0;
        for(int num:area){
            m=max(m,num);
        }
        return m;
    }
};
