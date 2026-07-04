class Solution {
public:
    int maxArea(vector<int>& heights){
        int maxA=0;
        int l=0,r=heights.size()-1;

        int mhl=0,mhr=0;
        while(l<heights.size() && r>=0 && l<r){
            printf("3");
            mhl=max(mhl,heights[l]);
            mhr=max(mhr,heights[r]);

            int h=min(mhr,mhl);
            int w=r-l;
            int area=h*w;
            maxA=max(maxA,area);

            if(heights[l]>heights[r])
                r--;
            else 
                l++;
        }

        return maxA;
    }
};
