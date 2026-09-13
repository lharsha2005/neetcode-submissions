class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        
        for(int i=0;i<s.size();i++){
            int l=i,r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                l--;
                r++;
                count++;
                // printf("a");
            }

            // if(((r-1)-(l+1)+1)>1)   count++;

            l=i,r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                l--;
                r++;
                count++;
                // printf("s");
            }

            // if(((r-1)-(l+1)+1)>1)   count++;
        }

        return count;
    }
};
