class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char ch:s){
            char prev;
            if(!stk.empty()) prev=stk.top();
            else if(stk.empty())    prev=NULL;
            stk.push(ch);

            if(stk.top()=='}' && prev=='{'){
                stk.pop();
                stk.pop();
            }
            else if(stk.top()==')' && prev=='('){
                stk.pop();
                stk.pop();
            }
            else if(stk.top()==']' && prev=='['){
                stk.pop();
                stk.pop();
            }
        }

        if(stk.empty()){
            return true;
        }else{
            return false;
        }
    }
};
