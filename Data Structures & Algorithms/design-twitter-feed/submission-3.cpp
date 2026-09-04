class Twitter {
public:
    int time=1;

    unordered_map<int,unordered_set<int>> followers;
    unordered_map<int,vector<pair<int,int>>> tweets;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        auto comp=[](pair<int,int> &a,pair<int,int> &b){
            return a.first>b.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)> pq;

        for(int follower: followers[userId]){
            for(auto tweet: tweets[follower]){
                if(pq.size()<10){
                    pq.push(tweet);
                }else{
                    pq.push(tweet);
                    pq.pop();
                }
            }
        }
        for(auto tweet: tweets[userId]){
            if(pq.size()<10){
                pq.push(tweet);
            }else{
                pq.push(tweet);
                pq.pop();
            }
        }

        vector<int> res;
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            res.push_back(tp.second);
        }

        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
