impl Solution {
    pub fn maximum_candies(candies: Vec<i32>, k: i64) -> i32 {
        let mut l: i64 = 0;
        let mut r: i64 = 10000000001;
        while l < r {
            let mid = l + (r - l) / 2;
            if mid == 0 {
                return 0;
            }
            let count: i64 = candies.iter().map(|&x| x as i64 / mid).sum();
            if count >= k {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        (r - 1).max(0) as i32
    }
}