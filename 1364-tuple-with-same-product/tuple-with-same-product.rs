use std::collections::HashMap;

impl Solution {
    pub fn tuple_same_product(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut res = 0;
        let mut mp: HashMap<i32, i32> = HashMap::new();

        for i in 0..n {
            for j in (i + 1)..n {
                *mp.entry(nums[i] * nums[j]).or_insert(0) += 1;
            }
        }

        for (_, v) in mp.iter() {
            res += v * (v - 1);
        }

        res * 4
    }
}