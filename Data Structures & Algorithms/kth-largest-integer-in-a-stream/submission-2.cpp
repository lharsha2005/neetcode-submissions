class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        int i=0;
        for(int i=0;i<nums.size();i++){
            if(pq.size()<k){
                pq.push(nums[i]);
            }
            else{
                pq.push(nums[i]);
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        if(pq.size()>=kth){
            pq.push(val);
            pq.pop();
        }else{
            pq.push(val);
        }

        return pq.top();
    }
};
