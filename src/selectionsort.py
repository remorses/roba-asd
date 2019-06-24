



def selectionsort(arr):
    for i in range(len(arr)):
        min = i
        for j in range(i, len(arr)):
            if j < min:
                min = j
        arr[j], arr[min] = arr[min], arr[j]
        