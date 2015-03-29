#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int alen = a.size();
        int blen = b.size();
        
        int tlen = max(alen, blen);
        char buf[tlen+1];
        memset(buf, 0, tlen+1);
        
        int carry = 0;
        for(int i=tlen; i>=0; --i) {
            int tmp;
            int aindex = alen - tlen + i - 1;
            int bindex = blen - tlen + i - 1;

            if(aindex >= 0 && bindex >= 0)
                tmp = a[aindex] - '0' + b[bindex] - '0' + carry;
            else if(aindex >= 0)
                tmp = a[aindex] - '0' + carry;
            else if(bindex >= 0) 
                tmp = b[bindex] - '0' + carry;
            else 
                tmp = carry;
            
            if(tmp > 1) {
                carry = 1;
                tmp -= 2;
            }
            else
                carry = 0;
            buf[i] = tmp + '0';
        }
        
        if(buf[0] == '0')
            return string(buf+1, buf+1+tlen);
        else
            return string(buf, buf+tlen+1);
    }
};

int main(int argc, char const *argv[])
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    Solution s;
    string s3 = s.addBinary(s1, s2);

    cout << s3 << endl;
    return 0;
}