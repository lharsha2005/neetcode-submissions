class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int l=0,r=n-1;
        int mid;
        while(l<=r){
            mid=(l+r)/2;

            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target){
                int l2=0,r2=m-1;
                int mid2;

                while(l2<=r2){
                    mid2=(l2+r2)/2;

                    if(matrix[mid][mid2]==target)   return true;
                    else if(matrix[mid][mid2]>target)   r2=mid2-1;
                    else if(matrix[mid][mid2]<target)   l2=mid2+1;
                }

                return false;
            }
            else if(matrix[mid][0]>target){
                r=mid-1;
            }
            else if(matrix[mid][0]<target){
                l=mid+1;
            }
        }

        return false;
    }
};
