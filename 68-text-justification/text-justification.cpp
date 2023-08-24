class Solution {
private:
    void addRemaining(string& str, int count, int rem) {
        int dist = rem / (count - 1);
        int extra = rem % (count - 1);
        string add = "";
        for(int i = 0; i < dist; i++) {
            add += ' ';
        }
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == ' ') {
                str.insert(i, add);
                if(extra) {
                    str.insert(i, " ");
                    extra--;
                }
                while(i < str.size() && str[i] == ' ') {
                    i++;
                }
            }
        }
    }
    void justify(vector<string>& result, vector<int>& wordCount, int maxWidth) {
        for(int i = 0; i < result.size(); i++) {
            if(result[i].back() == ' ') {
                result[i].pop_back();
            }
            if(wordCount[i] == 1 || i == result.size() - 1) {
                int rem = maxWidth - result[i].size();
                while(rem--) {
                    result[i] += ' ';
                }
            }
            else {
                int length = result[i].size();
                int remaining = maxWidth - length;
                addRemaining(result[i], wordCount[i], remaining);
            }
        }
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        string curr = "";
        int count = 0;
        vector<int> wordCount;
        for(int i = 0; i < words.size(); i++) {
            if(curr.size() + words[i].size() <= maxWidth) {
                curr += words[i];
                count++;
            }
            else {
                wordCount.push_back(count);
                count = 0;
                result.push_back(curr);
                curr = words[i];
                count++;
            }
            if(curr.size() == maxWidth) {
                wordCount.push_back(count);
                count = 0;
                result.push_back(curr);
                curr = "";
                continue;
            }
            curr += ' ';
        }
        if(!curr.empty()) {
            wordCount.push_back(count);
            count = 0;
            result.push_back(curr);
        }
        justify(result, wordCount, maxWidth);
        return result;
    }
};