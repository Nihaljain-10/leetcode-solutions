class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
         int pse[n],nse[n];
            stack<int>st;
            for(int i=0;i<n;i++){
                    while(!st.empty() && heights[st.top()]>=heights[i]){
                            st.pop();
                    }
                    if(st.empty())
                            pse[i]=0;
                    else
                            pse[i]=st.top()+1;
                    st.push(i);
            }
            while(!st.empty())
                    st.pop();
             for(int i=n-1;i>=0;i--){
                    while(!st.empty() && heights[st.top()]>=heights[i]){
                            st.pop();
                    }
                    if(st.empty())
                            nse[i]=n-1;
                    else
                            nse[i]=st.top()-1;
                    st.push(i);
            }
            int maxi=0;
            for(int i=0;i<n;i++){
                    maxi=max(maxi,heights[i]*(nse[i]-pse[i]+1));
            }
            return maxi;
    }
};