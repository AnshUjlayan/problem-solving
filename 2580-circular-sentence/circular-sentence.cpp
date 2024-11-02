class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> arr;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }
        arr.push_back(arr[0]);
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i][0] != arr[i - 1].back()) {
                return false;
            }
        }
        return true;
    }
};