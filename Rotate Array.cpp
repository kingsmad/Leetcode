#include <iostream>

using namespace std;
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if (!nums)
            return;
        k = k % n;
        int buf[k];
        memcpy(buf, nums+n-k, sizeof(int) * k);
        memmove(nums+k, nums, sizeof(int) * (n-k));
        memcpy(nums, buf, sizeof(int) * k);
        
        return;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    printf("\nPlease enter length & array\n");
    int len;
    cin >> len;
    
    int nums[len];
    for(int i=0; i<len; ++i)
        cin >> nums[i];
    printf("\nPlease enter rotate k:\n");
    
    int k;
    cin >> k;
    
    for(int i=0; i<len; ++i) {
        cout << nums[i] << " ";
    }
    
    sol.rotate(nums, len, k);
    
    for(int i=0; i<len; ++i) {
        cout << nums[i] << " ";
    }
    
    cout << endl;
}


