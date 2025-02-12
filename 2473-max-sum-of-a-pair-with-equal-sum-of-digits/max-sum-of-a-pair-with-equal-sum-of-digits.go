func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func sumDigits(x int) int {
    sum := 0
    for x > 0 {
        sum += x % 10
        x /= 10
    }
    return sum
}

func maximumSum(nums []int) int {
    mp := make(map[int]int)
    res := -1
    for _, num := range nums {
        dig := sumDigits(num)
        if val, exists := mp[dig]; exists {
            res = max(res, val+num)
        }
        mp[dig] = max(mp[dig], num)
    }
    return res
}