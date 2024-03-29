class Solution {
public:
    vector<int> ncr(int row){
        long long ans=1;
        vector<int> ansrow;
        ansrow.push_back(1);
        for(int col=1;col<row;col++){
            ans*=(row-col);
            ans/=col;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(ncr(i));
        }
        return ans;
    }
};