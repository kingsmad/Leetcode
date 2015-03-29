#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        __kquickSort(A, A+n, less<int>());
    }
    
public:
    template<class BiPred>
    int* __partion(int* first, int* last, BiPred pred) {
        --last;
        int val = *last;
        int* t = last;
        
        while (first < last) {
            while (pred(*first, val) && first < last) {
                ++first;
            }
            if (first == last)
                break;
            while (!pred(*last, val) && first < last) {
                --last;
            }
            if (first == last) {
                break;
            }
            
            iter_swap(first, last);
        }
        
        iter_swap(first, t);
        
        return first;
    }
    
    template<class BiPred>
    void __kquickSort(int* first, int* last, BiPred pred) {
        int* pv = __partion(first, last, pred);
        if (pv != first)
            __kquickSort(first, pv, pred);
        if (pv != last-1)
            __kquickSort(pv+1, last, pred);
    }
};

int main(int argc, char const *argv[])
{
    int len;
    cin >> len;
    
    int num[len];
    for(int i=0; i<len; ++i)
        cin >> num[i];
    
    Solution s;
    s.sortColors(num, len);
//    s.__partion(num, num+len, less<int>());
    
    for(int i=0; i<len; ++i)
        cout << num[i] << " ";

    cout << endl;
    return 0;
}