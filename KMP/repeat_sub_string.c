class Solution {
private:
    bool kmp(string s){
        int n=s.size();
        vector<int> next(n+1,-1);

        int i=0, j=-1;
        while(i<n){
            if(j==-1 || s[j]==s[i]){
                ++i;
                ++j;

                if(s[j]!=s[i]){
                    next[i] = j;
                }else{
                    next[i] = next[j];
                }
            }else{
                j=next[j];
            }
        }

        for(int i=0;i<=n;++i){
            cout << next[i] << " ";
        }

        return next[n]!=0 && (n%(n-next[n]))==0; 
    }

public:
    bool repeatedSubstringPattern(string s) {
        return kmp(s);
    }
};