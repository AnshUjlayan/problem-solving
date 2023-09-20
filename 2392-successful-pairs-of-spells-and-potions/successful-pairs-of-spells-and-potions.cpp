class Solution {
  public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      sort(potions.begin(), potions.end());
      vector<int> result;
      for(int i = 0; i < spells.size(); i++) {
        long long minStrength = (success + spells[i] - 1) / spells[i];
        int idx = lower_bound(potions.begin(), potions.end(), minStrength) - potions.begin();
        result.push_back(potions.size() - idx);
      }
      return result;
    }
};