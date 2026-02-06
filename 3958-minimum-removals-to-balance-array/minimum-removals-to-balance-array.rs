impl Solution {
    pub fn min_removal(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort_unstable();

        let mut res = usize::MIN;
        let n = nums.len();

        let mut l = 0;
        for r in 0..n {
            while nums[r] as i64 > nums[l] as i64 * k as i64 {
                l += 1;
            }
            res = res.max(r - l + 1);
        }

        (n - res) as i32
    }
}