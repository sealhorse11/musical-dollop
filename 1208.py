def cal_sum(arr, map:dict, n):
    if len(arr) == 0:
        if n in map.keys():
            map[n] += 1
        else:
            map[n] = 1
        return
    
    cal_sum(arr[1:], map, n)
    cal_sum(arr[1:], map, n + arr[0])
    
    return

n, s = map(int, input().split())
arr = list(map(int, input().split()))
arr_size = len(arr)

dict1 = dict()
dict2 = dict()

cal_sum(arr[:arr_size // 2], dict1, 0)
dict1[0] -= 1
cal_sum(arr[arr_size // 2:], dict2, 0)
dict2[0] -= 1

ans = 0

for val, count in dict1.items():
    if (s - val) in dict2.keys():
        ans += count * dict2[s - val]

if s in dict1.keys():
    ans += dict1[s]
if s in dict2.keys():
    ans += dict2[s]

print(ans)