# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(s, c):
    # Implement your solution here
    # pass
    ind = set([0, len(s)])
    ans = 0
    for i in c:
        ind.add(i)
        list_index = list(ind)
        start = list_index.index(i)-1
        end = 2+start
        q = set()
        ans += 1
        for ch in s[:list_index[start]]:
            q.add(ch)
        if (len(q) != list_index[start]):
            continue
        q.clear()

        for ch in s[list_index[start]:i]:
            q.add(ch)
        if (len(q) != (i-list_index[start])):
            continue
        q.clear()

        for ch in s[i:list_index[end]]:
            q.add(ch)
        if (len(q) != (list_index[end]-i)):
            continue
        q.clear()

        for ch in s[end:len(s)]:
            q.add(ch)
        if (len(q) != (len(s) - list_index[end])):
            continue

        return ans
    
    return ans