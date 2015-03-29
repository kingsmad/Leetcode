 #include <vector>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define zero 0.000001
using namespace std;

struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };
 
 #define zero 0.000001
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = points.size();
        if(n < 3)
            return n;
            
        vector<double> maxes;
        int A[n];
        memset(A, 0, n*sizeof(int));
        
        for(int i=0; i<n; ++i) {
            int nilSlopCnt = 0;
            for(int j=0; j<n; ++j) {
                if(__equals(points[i], points[j]))
                    continue;
                else if(points[i].x = points[j].x) {
                    ++nilSlopCnt;
                }
                else
                    maxes.push_back(static_cast<double>(points[i].y - points[j].y) / (points[i].x - points[j].x));
            }
            sort(maxes.begin(), maxes.end());
            A[i] = max(nilSlopCnt, __getMaxFreq(maxes));
            maxes.clear();
        }
        
        int t = A[0];
        for(int i=1; i<n; ++i) 
            if(A[i] > t)
                t = A[i];
                
        return t + 1;
    }
    
    
    inline bool __equals(Point& p1, Point& p2) {
        if(p1.x == p2.x && p2.y == p1.y)
            return true;
        else
            return false;
    }
    
    int __getMaxFreq(vector<double>& A) {
        int len = A.size();
        int m = 1;
        int cnt = 1;
        for(int i=1; i<len; ++i) {
            double t = A[i] - A[i-1];
            if(fabs(t) < zero) {
                ++cnt;
                if(cnt > m)
                    m = cnt;
            }
            else
                cnt = 1;
        }
        
        return m;
    }
};

int main(int argc, char const *argv[])
{
    int len ;
    cin >> len;

    double A[len];

    for(int i=0; i<len; ++i) {
        cin >> A[i];
    }

    vector<double> ans(A, A+len);

    cout << __getMaxFreq(ans);    
    return 0;
}