impl Solution {
    pub fn find_the_prefix_common_array(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
        let n: usize = a.len();
        let mut perm: Vec<bool> = vec![false; 51];
        let mut count: i32 = 0;
        let mut res: Vec<i32> = Vec::new();
        for i in 0..n {
            if perm[a[i] as usize] {
                count += 1;
            }
            if perm[b[i] as usize] || a[i] == b[i] {
                count += 1;
            }
            perm[a[i] as usize] = true;
            perm[b[i] as usize] = true;
            res.push(count);
        }
        res
    }
}