impl Solution {
    pub fn minimum_difference(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort_unstable();
        nums.windows(k as usize).map(|w| w.last().unwrap() - w.first().unwrap()).min().unwrap()
    }
}