class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> op{"+","-","*","/"};
        stack<int> stk;

        for(string ch:tokens){
            if(op.find(ch)==op.end()){
                stk.push(stoi(ch));
            }else{
                int x=stk.top();
                stk.pop();
                int y=stk.top();
                stk.pop();
                int temp;
                if(ch=="+"){
                    temp=y+x;
                }
                else if(ch=="-"){
                    temp=y-x;
                }
                else if(ch=="*"){
                    temp=y*x;
                }
                else if(ch=="/"){
                    temp=y/x;
                }
                stk.push(temp);
            }
        }

        return stk.top();
    }
};
