class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> hash;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &temp = hash[key];

        int l=0,r=temp.size()-1;
        string ans="";
        while(l<=r){
            int mid=(l+r)/2;

            if(temp[mid].first<=timestamp){
                ans=temp[mid].second;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }

        return ans;
    }
};
