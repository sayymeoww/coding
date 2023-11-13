n, k = map(int, input().split())
nums = sorted(list(map(int, input().split())))


def check(x):
    global n, k

    cur = (nums[0], nums[0] + x)
    cnt = k - 1
    i = 1

    while (i < len(nums)) and cnt >= 0:
        if cur[1] < nums[i]:
            cur = (nums[i], nums[i] + x)
            cnt -= 1
        i += 1

    return cnt >= 0


def f(l, r):
    while l < r:
        m = (l + r) // 2
        if check(m):
            r = m
        else:
            l = m + 1
    return l


print(f(0, nums[n - 1] - nums[0]))
