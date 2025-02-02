impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let dupe = [nums.clone(), nums].concat();
        dupe.windows(n).any(|x| x.windows(2).all(|w| w[0] <= w[1]))
    }
}