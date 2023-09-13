class Solution {
  public:
    int candy(vector<int>& ratings) {
      int result = ratings.size();
      vector<int> candies(ratings.size(), 1);
      for(int i = 0; i < ratings.size(); i++) {
        int neighbourL = i - 1 >= 0 ? ratings[i - 1] : 1e5;
        int prevState = candies[i];
        if(neighbourL < ratings[i]) {
          candies[i] = max(candies[i], candies[i - 1] + 1);
        }
        result += candies[i] - prevState;
      }
      for(int i = ratings.size() - 1; i >= 0; i--) {
        int neighbourR = i + 1 < ratings.size() ? ratings[i + 1] : 1e5;
        int prevState = candies[i];
        if(neighbourR < ratings[i]) {
          candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        result += candies[i] - prevState;
      }
      return result;
    }
};