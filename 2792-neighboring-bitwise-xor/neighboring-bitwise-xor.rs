impl Solution {
    pub fn does_valid_array_exist(derived: Vec<i32>) -> bool {
        let mut a = 0;
        let mut b = 1;
        for x in derived.iter() {
            a ^= x;
            b ^= x;
        }
        a == 0 || b == 1
    }
}