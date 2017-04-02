#include <string>
#include<iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // We can simply just start from the first end of string and keep
        // going to match.
        bool result = false;
        bool reset = true;
        
        int idx_to_match = 0;
        int last_match = -1;
        
        char first = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (reset) {
                if (s[i] == first) {
                    reset = false;
                    idx_to_match = 1;
                    last_match = i-1;
                } else {
                    last_match = i;
                }
            } else {
                if (s[i] == s[idx_to_match]) {
                     idx_to_match++;
                 } else {
                     reset = true;
                     last_match = i;
                }
            }
        }
        
        if (reset || ((s.size() % (last_match+1) == 0)) {
            return false;
        } else {
            return true;
        }
    }
};
