// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/description/
class Solution {
public:
    #define N (int)2e5+1
    int ftree[N],n;
    void update(int* ft,int idx,int val){
        for(;idx<n;){
            ft[idx] += val;
            idx |= (idx+1);
        }
        return ;
    }
    int query(int* ft,int idx){
        int sum = 0;
        for(;idx>=0;){
            sum += ft[idx];
            idx &= (idx+1);
            idx--;
        }
        return sum;
    }
    int minMovesToMakePalindrome(string s) {
        n = s.size();
        int i = 0,swaps = 0,unique=0,fixes=0;
        vector<vector<int>> pos(26);
        vector<pair<int,int>> pairs(26);
        long long int present = 0;
        memset(ftree,0,sizeof(ftree));
        for(i=0;i<n;i++){
            pos[s[i]-'a'].push_back(i);
            pairs[s[i]-'a'] = {0,pos[s[i]-'a'].size()-1};
            present |= (1<<(s[i]-'a'));
            update(ftree,i,+1);
        }
         int r=0;
        while(1) 
        {
            int charToRemove = -1,distanceToCover = INT_MAX;
            int end = query(ftree,n-1);
            for(i=0;i<26;i++){
                    if(present&(1<<i))
                    {
                            int first=pos[i][pairs[i].first];
                            int second=pos[i][pairs[i].second];
                            if(first<=second)
                            {
                                // distance to put first occurence of curr letter to L
                                int currFirst = query(ftree,first) - 1;
                                // distance to put last occurence of curr letter to R
                                int currLast = end - query(ftree,second);
                                // minimize swap_count 
                                if((currFirst+currLast)<distanceToCover){
                                    distanceToCover = currFirst+currLast;
                                    charToRemove = i;
                                }
                            }
                    }
            }
            if(charToRemove!=-1){
                        fixes += (((pairs[charToRemove].first!=pairs[charToRemove].second))?(2):(1));
                        swaps += distanceToCover;
                        update(ftree,pos[charToRemove][pairs[charToRemove].first],-1);
                        update(ftree,pos[charToRemove][pairs[charToRemove].second],-1);
                        // remove them 
                        pairs[charToRemove].first++;
                        pairs[charToRemove].second--;
            }
            if(fixes==n){
                break;
            }
        }   
        return swaps;
    }
};
