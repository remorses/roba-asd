



def insertionsort(arr):
    for i in range(1, len(arr)):
        while i > 0 and arr[i-1] > arr[i]:
            arr[i-1], arr[i] = arr[i], arr[i-1]
            i -= 1
