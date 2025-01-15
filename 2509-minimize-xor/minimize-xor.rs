impl Solution {
    pub fn minimize_xor(num1: i32, num2: i32) -> i32 {
        let mut res = num1;
        let mut bits_to_adjust = num2.count_ones() as i32 - num1.count_ones() as i32;
        if bits_to_adjust > 0 {
            for i in 0..32 {
                if bits_to_adjust == 0 {
                    break;
                }
                if (res & (1 << i)) == 0 {
                    res |= 1 << i;
                    bits_to_adjust -= 1;
                }
            }
        } else {
            bits_to_adjust = -bits_to_adjust;
            for i in 0..32 {
                if bits_to_adjust == 0 {
                    break;
                }
                if (res & (1 << i)) != 0 {
                    res &= !(1 << i);
                    bits_to_adjust -= 1;
                }
            }
        }
        res
    }
}