class Solution {
public:
    int maxDepth(string s) {
        int openbrackets=0;
        int result=0;
        for(auto ch:s){
            if(ch=='(') openbrackets++;
            else if(ch==')')openbrackets--;
             result=max(result,openbrackets);
        }
        return result;
    }
};