class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
    int n=0;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
        } else {
            large.push(num);
        }

        if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        }
        else if (large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
        n++;
    }
    
    double findMedian() {
        if(n%2==0){
            return (double)(small.top()+large.top())/2;
        }else{
            if(small.size()>large.size()){
                return (double)small.top();
            }else{
                return (double)large.top();
            }
        }

        return 0.0;
    }
};
