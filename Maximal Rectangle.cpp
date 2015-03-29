class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int rlen = matrix.size();
        if(rlen == 0)
            return 0;
        int clen = matrix[0].size();
        
        for(int i=0; i<rlen; ++i) {
            int cnt = 0;
            for(int k=clen-1; k>=0; --k) {
                cnt = (matrix[i][k] == '1') ? (cnt+1) : 0;
                matrix[i][k] = cnt;
            }
        }
        
        int ans = 0;
        vector<int> vec(rlen, 0);
        for(int i=0; i<clen; ++i) {
            for(int k=0; k<rlen; ++k) {
                vec[k] = matrix[k][i];
            }
            ans = max(ans, largestRectangleArea(vec));
        }
        
        return ans;
    }
    
    int largestRectangleArea(vector<int> &height) {
        if(height.empty())
            return 0;
        
        height.push_back(0);
        stack<int> istack;
        int ans = 0;
        
        for(int i=0; i<height.size(); ++i) {
            if(istack.empty() || height[i] >= height[istack.top()])
                istack.push(i);
            else {
                while(!istack.empty() && height[istack.top()] >= height[i]) {
                    int p = istack.top();
                    istack.pop();
                    int tmp = height[p] * (istack.empty() ? i : i-istack.top()-1);
                    /*关于序号，若余下stack为空，istack.top()就不存在*/
                    ans = max(ans, tmp);
                }
                istack.push(i);
            }
        }
        
        height.pop_back();
        return ans;
    }
};