




def bubblesort(arr):
    for i in range(len(arr)):
        for j in range(1, len(arr)-i):
            if arr[j-1] > arr[j]:
                arr[j], arr[j-1] = arr[j-1], arr[j]


def bubblesort2(arr):
    swapped = True
    while swapped:
        swapped = False
        for i in range(1, len(arr)):
            if arr[i-1] > arr[i]:
                arr[i], arr[i-1] = arr[i-1], arr[i]
                swapped = True
