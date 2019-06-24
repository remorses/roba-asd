

def merge(a: list, b: list):
    result = []
    while a and b:
        if b[0] > a[0]:
            result.append(a[0])
            a.pop(0)
        else:
            result.append(b[0])
            b.pop(0)
    return result + a + b


def mergesort(arr):
    if len(arr) == 1:
        return arr
    m = len(arr) // 2
    a = mergesort(arr[:m])
    b = mergesort(arr[m:])
    return merge(a, b)




