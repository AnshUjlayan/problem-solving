func tupleSameProduct(nums []int) int {
    mp := make(map[int]int)
    count := 0

    n := len(nums)
    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            product := nums[i] * nums[j]
            mp[product]++
        }
    }

    for _, x := range mp {
        count += (x * (x - 1)) / 2
    }

    return count * 8
}