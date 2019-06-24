

def merge(a: list, b: list):
    result = []
    length = len(a) if len(a) < len(b) else len(b)
    i, j = 0, 0
    while i < len(a) and j < len(b):
        if a[i] < b[j]:
            result.append(a[i])
            i += 1
        else:
            result.append(b[j])
            j += 1
    # for k in range(i, len(a)):
    #     result.append(a[k])
    # for k in range(j, len(b)):
    #     result.append(b[k])
    return result + a[i:] + b[j:]


def mergesort(arr):
    if len(arr) == 1:
        return arr
    m = len(arr) // 2
    a = mergesort(arr[:m])
    b = mergesort(arr[m:])
    return merge(a, b)




