class Solution {
private:
    void recur(int ind,int target,vector<int> &ds,vector<int>& candidates,vector<vector<int>> &ans){
        int n=candidates.size();
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i!=ind && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            ds.push_back(candidates[i]);
            recur(i+1,target-candidates[i],ds,candidates,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        recur(0,target,ds,candidates,ans);
        return ans;
    }
};