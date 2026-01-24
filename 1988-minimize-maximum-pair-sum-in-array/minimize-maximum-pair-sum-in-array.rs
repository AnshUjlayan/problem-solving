impl Solution {
    pub fn min_pair_sum(mut nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let n = nums.len();
        nums.sort();
        for i in 0..(n / 2) {
            res = res.max(nums[i] + nums[n - i - 1]);
        }
        res
    }
}