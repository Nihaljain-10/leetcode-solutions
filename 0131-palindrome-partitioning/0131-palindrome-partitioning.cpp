class Solution {
private:
    void recur(int ind,string s,vector<string> &path,vector<vector<string>> &res){
        int n=s.size();
        if(ind==n){
            res.push_back(path);
            return;
        }
        for(int i=ind;i<n;i++){
            if(isPalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                recur(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        recur(0,s,path,res);
        return res;
    }
};