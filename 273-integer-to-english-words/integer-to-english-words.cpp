class Solution {
private:
    unordered_map<int, string> ump {
        {0, ""},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
        {100, "Hundred"},
        {1000, "Thousand"},
        {1000000, "Million"},
        {1000000000, "Billion"}
    };

    vector<string> getSlimy(int num, long long mul) {
        if (!num)
            return {};
            
        vector<string> res;
        if (num && num > 99) {
            res.push_back(ump[num / 100]);
            res.push_back(ump[100]);
            num %= 100;
        }

        if (num && num <= 19) {
            res.push_back(ump[num]);
            num = 0;
        }

        if (num) {
            res.push_back(ump[(num / 10) * 10]);
            num %= 10;
        }

        if (num)
            res.push_back(ump[num]);

        if (mul > 1)
            res.push_back(ump[mul]);
        
        return res;
    }

public:
    string numberToWords(int num) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        if (!num)
            return "Zero";

        long long mul = 1;
        vector<vector<string>> dard;
        while (num) {
            dard.push_back(getSlimy(num % 1000, mul));
            num /= 1000;
            mul *= 1000;
        }
        reverse(dard.begin(), dard.end());

        string result = "";
        for (vector<string>& dukh : dard)
            for (string& pain : dukh)
                result += " " + pain;

        return string(result.begin() + 1, result.end());
    }
};