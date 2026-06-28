class Solution {
public:
    int numberOfSubstrings(string s) {
        int c=0;
        vector<int>ls(3,-1);
        for(int i=0;i<s.size();i++){
            ls[s[i]-'a']=i;
            if(ls[0]!=-1 && ls[1]!=-1 && ls[2]!=-1){
                c=c+(1+min(ls[0],min(ls[1],ls[2])));
            }
        }
        return c;
    }
};