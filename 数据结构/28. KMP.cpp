class Solution {
public:
    vector<int> next;
    void generateNext(string needle) {
        next.push_back(0);
        int prelen = 0;
        int i = 1;
        while(i < needle.size()){
            if (needle[prelen] == needle[i]) {
                prelen ++;
                next.push_back(prelen);
                i ++;
            } else {
                if (prelen == 0) {
                    next.push_back(0);
                    i ++;
                } else {
                    prelen = next[prelen - 1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        generateNext(needle);
        int i = 0, j = 0;
        while(i < m) {
            if(haystack[i] == needle[j]) {
                i ++, j ++;
            }
            else if(j > 0) {
                j = next[j - 1];
            }
            else i ++;

            if(j == needle.size()) return i - j;
        }
        return -1;
    }
};