impl Solution {
    pub fn minimum_length(s: String) -> i32 {
        let mut res: i32 = 0;
        let mut dict: Vec<i32> = vec![0; 26];
        for c in s.chars() {
            dict[(c as usize) - ('a' as usize)] += 1;
        }
        for i in 0..26 {
            if dict[i] != 0 {
                res += 1 + (dict[i] - 1) % 2;
            }
        }
        res
    }
}