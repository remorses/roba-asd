


def bisect(arr, left, right, e):
    if left > right: return -1
    m = (left + right +1) // 2
    if e < arr[m]:
        return bisect(arr, left, m-1, e)
    elif e > arr[m]:
        return bisect(arr, m+1, right, e)
    else:
        return m