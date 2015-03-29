class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> pool(numbers);
        std::sort(pool.begin(), pool.end());
        vector<int>::iterator first = pool.begin();
        vector<int>::iterator last = pool.end();
        --last;

        for(; first<=last; ){
        	if(*first + *last < target)
        		++first;
        	else if (*first + *last > target)
        		--last;
        	else 
        		break;
        }

        vector<int> result;
        vector<int>::iterator pos_first = find(numbers.begin(), numbers.end(), *first);
        vector<int>::iterator pos_last = find(numbers.begin(), numbers.end(), *last);
        
        if(pos_first == pos_last)
        	++pos_last;
        result.push_back(distance(numbers.begin(), pos_first) + 1);
        result.push_back(distance(numbers.begin(), pos_last) + 1);
        sort(result.begin(), result.end());
        return result;
    }
};