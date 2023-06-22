class Solution {
private:
    void recur(int ind,int target,vector<int> &ds,vector<int>& candidates,vector<vector<int>> &ans){
        int n=candidates.size();
        if(ind==n){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            recur(ind,target-candidates[ind],ds,candidates,ans);
            ds.pop_back();
        }
        recur(ind+1,target,ds,candidates,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        recur(0,target,ds,candidates,ans);
        return ans;
    }
};