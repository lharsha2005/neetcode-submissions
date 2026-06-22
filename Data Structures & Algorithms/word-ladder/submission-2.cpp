class Solution {
public:
    unordered_map<string,vector<string>> hash;

    bool check(string w1,string w2){
        int n=w1.size();
        int count=0;
        int i=0;
        while(i<n){
            if(w1[i]==w2[i])    count++;
            i++;
        }

        if(count==n-1)  return true;
        return false;
    }

    bool dfs(string beginWord,string endWord,string par,unordered_set<string> &visited){
        if(visited.find(beginWord)!=visited.end())  return false;
        visited.insert(beginWord);
        
        for(string wrd:hash[beginWord]){
            if(par==wrd)    continue;

            if(dfs(wrd,endWord,beginWord,visited))  return true;
        }

        return false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        // printf("%b",check("bat","bot"));
        for(int i=0;i<wordList.size();i++){
            cout<<wordList[i]+":";
            for(int j=0;j<wordList.size();j++){
                if(check(wordList[i],wordList[j])){
                    hash[wordList[i]].push_back(wordList[j]);
                    cout<<wordList[j]+" ";
                }
            }
            cout<<"\n";
        }

        unordered_set<string> visited;
        // if(dfs(beginWord,endWord,"*",visited))  return count;

        int level=1;
        queue<string> qu;
        qu.push(beginWord);
        visited.insert(beginWord);

        int ans=INT_MAX;
        while(!qu.empty()){
            int sz = qu.size();

            while(sz--){
                string wrd = qu.front();
                qu.pop();

                if(wrd == endWord)
                    return level;

                for(string st : hash[wrd]){
                    if(visited.find(st) != visited.end())   continue;

                    visited.insert(st);
                    qu.push(st);
                }
            }

            level++;
        }

        return 0;
    }
};
