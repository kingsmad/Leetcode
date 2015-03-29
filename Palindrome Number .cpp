class Solution {
public:
    bool isPalindrome(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int reversedNum = 0;
        int origin = x;
        for(; origin>0; origin /= 10) 
        	reversedNum = 10* reversedNum + origin%10;
        return reversedNum == x;
    }
};