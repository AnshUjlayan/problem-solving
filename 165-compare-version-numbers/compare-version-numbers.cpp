class Solution {
public:
    int compareVersion(string version1, string version2) {
        string::iterator it1 = version1.begin();
        string::iterator it2 = version2.begin();
        while(it1 != version1.end() || it2 != version2.end()) {
            string::iterator e1 = find(it1, version1.end(), '.');
            string::iterator e2 = find(it2, version2.end(), '.');
            int v1 = (it1 != version1.end()) ? stoi(string(it1, e1)) : 0;
            int v2 = (it2 != version2.end()) ? stoi(string(it2, e2)) : 0;
            it1 = (e1 != version1.end()) ? e1 + 1 : version1.end();
            it2 = (e2 != version2.end()) ? e2 + 1 : version2.end();
            if(v1 < v2) {
                return -1;
            }
            else if(v1 > v2) {
                return 1;
            }
        }
        return 0;
    }
};