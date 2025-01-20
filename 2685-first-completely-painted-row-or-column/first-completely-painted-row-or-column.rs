impl Solution {
    pub fn first_complete_index(arr: Vec<i32>, mat: Vec<Vec<i32>>) -> i32 {
        let m = mat.len();
        let n = mat[0].len();

        let mut row = vec![n as i32; m];
        let mut col = vec![m as i32; n];
        let mut map = vec![(0, 0); n * m + 1];

        for i in 0..m {
            for j in 0..n {
                map[mat[i][j] as usize] = (i, j);
            }
        }

        for (idx, num) in arr.iter().enumerate() {
            let (i, j) = map[*num as usize];
            row[i] -= 1;
            col[j] -= 1;
            if row[i] == 0 || col[j] == 0 {
                return idx as i32;
            }
        }

        -1
    }
}