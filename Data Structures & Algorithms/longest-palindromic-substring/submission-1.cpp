class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        int rl=0;

        for(int i=0;i<s.size();i++){
            int r=i,l=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(rl<(r-l+1)){
                    rl=(r-l+1);
                    res=s.substr(l,(r-l+1));
                }
                l--;
                r++;
            }

            l=i;
            r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(rl<(r-l+1)){
                    rl=(r-l+1);
                    res=s.substr(l,(r-l+1));
                }
                l--;
                r++;
            }
        }

        return res;
    }
};
