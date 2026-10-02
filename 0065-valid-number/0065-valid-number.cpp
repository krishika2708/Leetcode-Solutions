class Solution {
public:
    bool isNumber(string s) {
        bool digitseen=false;
        bool dotseen=false;
        bool eseen=false;
        bool digitafterE=true;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            //digit
            if(isdigit(c)){
                digitseen=true;
                if(eseen)
                digitafterE=true;
            }
            else if(c=='.'){
                if(dotseen||eseen)
                return false;
                dotseen=true;
            }
            else if(c=='e'||c=='E'){
                if(eseen||!digitseen)return false;
                eseen=true;
                digitafterE=false;
            }
            else if(c=='+'||c=='-'){
                if(i!=0&& s[i-1]!='e'&& s[i-1]!='E')
                return false;
            }
            else{
                return false;
            }
        }
        return digitseen && digitafterE;
    }
};