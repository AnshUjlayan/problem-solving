impl Solution {
    pub fn xor_all_nums(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let mut res = 0;
        if nums1.len() & 1 == 1 {
            res ^= nums2.iter().fold(0, |acc, &x| acc ^ x);
        }
        if nums2.len() & 1 == 1 {
            res ^= nums1.iter().fold(0, |acc, &x| acc ^ x);
        }
        res
    }
}