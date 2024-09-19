class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<vector<vector<int>>> memo(
            expression.length(), vector<vector<int>>(expression.length()));
        return computeResults(expression, memo, 0, expression.length() - 1);
    }

private:
    vector<int> computeResults(string& expression,
                               vector<vector<vector<int>>>& memo, int start,
                               int end) {
        if (!memo[start][end].empty()) {
            return memo[start][end];
        }

        vector<int> results;

        if (start == end) {
            results.push_back(expression[start] - '0');
            return results;
        }

        if (end - start == 1 && isdigit(expression[start])) {
            int tens = expression[start] - '0';
            int ones = expression[end] - '0';
            results.push_back(10 * tens + ones);
            return results;
        }

        for (int i = start; i <= end; i++) {
            char currentChar = expression[i];
            if (isdigit(currentChar)) {
                continue;
            }

            vector<int> leftResults =
                computeResults(expression, memo, start, i - 1);
            vector<int> rightResults =
                computeResults(expression, memo, i + 1, end);

            for (int leftValue : leftResults) {
                for (int rightValue : rightResults) {
                    switch (currentChar) {
                    case '+':
                        results.push_back(leftValue + rightValue);
                        break;
                    case '-':
                        results.push_back(leftValue - rightValue);
                        break;
                    case '*':
                        results.push_back(leftValue * rightValue);
                        break;
                    }
                }
            }
        }
        memo[start][end] = results;
        return results;
    }
};