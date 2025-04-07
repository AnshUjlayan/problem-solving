use std::collections::HashSet;

impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut dp = HashSet::new();
        dp.insert(nums[0]);
        for i in 1..n {
            let mut next_dp = HashSet::new();
            for &j in dp.iter() {
                next_dp.insert(j + nums[i]);
                next_dp.insert(j - nums[i]);
            }
            dp = next_dp;
        }
        dp.contains(&0)
    }
}