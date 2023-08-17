import sys

def lower_bound(nums, target):

    left, right = 0, len(nums)

    while left < right:
        mid = left + (right - left) // 2

        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid

    return right


def upper_bound(nums, target):

    left, right = 0, len(nums)

    while left < right:
        mid = left + (right - left) // 2

        if nums[mid] <= target:
            left = mid + 1
        else:
            right = mid

    return right

def safe(idx1, idx2, target_idx, size)->bool:
    return (idx1 < idx2 and idx2 < target_idx) and (0 <= target_idx < size)


input = sys.stdin.readline

N = int(input().rstrip())
value_array = list(map(int, input().rstrip().split()))

value_array.sort()

answer_pair = (0, 0, 0)
answer_pair_sum = 3000000000

for i, first in enumerate(value_array):
    for _j, second in enumerate(value_array[i+1:]):
        j = i + 1 + _j
        target = -first-second
        target_idx = lower_bound(value_array, target)
        target_idx2 = upper_bound(value_array, target)
        
        if safe(i, j, target_idx - 1, len(value_array)) and abs(first + second + value_array[target_idx - 1]) < answer_pair_sum:
            answer_pair_sum = abs(first + second + value_array[target_idx - 1])
            answer_pair = (first, second, value_array[target_idx - 1])
        
        if safe(i, j, target_idx, len(value_array)) and abs(first + second + value_array[target_idx]) < answer_pair_sum:
            answer_pair_sum = abs(first + second + value_array[target_idx])
            answer_pair = (first, second, value_array[target_idx])
            
        if safe(i, j, target_idx + 1, len(value_array)) and abs(first + second + value_array[target_idx + 1]) < answer_pair_sum:
            answer_pair_sum = abs(first + second + value_array[target_idx + 1])
            answer_pair = (first, second, value_array[target_idx + 1])
            
        if safe(i, j, target_idx + 2, len(value_array)) and abs(first + second + value_array[target_idx + 2]) < answer_pair_sum:
            answer_pair_sum = abs(first + second + value_array[target_idx + 2])
            answer_pair = (first, second, value_array[target_idx + 2])
        
        if safe(i, j, target_idx2, len(value_array)) and abs(first + second + value_array[target_idx2]) < answer_pair_sum:
            answer_pair_sum = abs(first + second + value_array[target_idx2])
            answer_pair = (first, second, value_array[target_idx2])
        

print(answer_pair[0], answer_pair[1], answer_pair[2])
