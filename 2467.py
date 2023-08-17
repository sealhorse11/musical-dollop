def lower_bound(nums, target):

    left, right = 0, len(nums)

    while left < right:  # left와 right가 만나는 지점이 target값 이상이 처음 나오는 위치
        mid = left + (right - left) // 2

        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid

    return right

N = int(input())
value_array = list(map(int, input().split()))

answer_pair = (0, 0)
answer_pair_sum = 2000000000

for i, val in enumerate(value_array):
    target = -val
    target_idx = lower_bound(value_array, target)
    
    if target_idx - 1 > 0 and i != target_idx - 1 and abs(val + value_array[target_idx - 1]) < answer_pair_sum:
        answer_pair_sum = abs(val + value_array[target_idx - 1])
        answer_pair = (val, value_array[target_idx - 1])
        
    if 0 < target_idx < len(value_array) and i != target_idx and abs(val + value_array[target_idx]) < answer_pair_sum:
        answer_pair_sum = abs(val + value_array[target_idx])
        answer_pair = (val, value_array[target_idx])
    
    if target_idx + 1 < len(value_array) and i != target_idx + 1 and abs(val + value_array[target_idx + 1]) < answer_pair_sum:
            answer_pair_sum = abs(val + value_array[target_idx + 1])
            answer_pair = (val, value_array[target_idx + 1])

print(answer_pair[0], answer_pair[1])