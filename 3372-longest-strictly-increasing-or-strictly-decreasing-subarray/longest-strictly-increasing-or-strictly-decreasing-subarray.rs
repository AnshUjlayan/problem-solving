impl Solution {
    pub fn longest_monotonic_subarray(nums: Vec<i32>) -> i32 {
        let (n, mut l1, mut l2, mut res) = (nums.len(), 0, 0, 1);
        for i in 1..n {
            if nums[i] <= nums[i - 1] {
                l1 = i;
            }
            if nums[i] >= nums[i - 1] {
                l2 = i;
            }
            res = res.max(i - l1 + 1).max(i - l2 + 1);
        }
        res as i32
    }
}