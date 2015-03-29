
// struct m_comp : public binary_function<pair<int, int>, pair<int, int>, bool> {
// 	bool operator(pair<int, int>& first, pair<int, int>& last) {
// 		return first.first < last.first;
// 	}
// };

class Solution {
public:
    int maxArea(vector<int> &height) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int result = 0;
        int len = height.size();

        for(int i=0; i<len; ++i) {
        	int pi = 0;
        	while(pi < i) {
        		if(height[pi] >= height[i]) {
        			result = max((i - pi) * height[i], result);
        			break;
        		}
        		else 
        			++pi;
        	}
        	
        	int np = 2 * i - pi;
        	pi = len - 1;

        	while(pi > np) {
        		if(height[pi] >= height[i]) {
        			result = max((pi - i) * height[i], result);
        			break;
        		}
        		else 
        			--pi;
        	}
        }

        return result;
    }
};


/*
 int n = height.size();
        if(n <= 1){
            return 0;
        }
        int b = 0;
        int e = n-1;
        int s = (e-b) * MIN(height[b], height[e]);
        while(b < e){
            if(height[e] <= height[b]){
                e--;
            }else{
                b++;
            }
            if(b < e){
                int tmp = (e-b) * MIN(height[b], height[e]);
                if(s < tmp){
                    s = tmp;
                }
            }
        }
        return s;
*/