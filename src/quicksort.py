
import random



def partition(arr, left, right):
    index = random.randint(left, right)
    pivot = arr[index]
    while left < right:
        while arr[left] < pivot:
            left += 1
        while arr[right] > pivot:
            right -= 1
        if left <= right:
            arr[right], arr[left] = arr[left], arr[right]
            right -= 1
            left += 1
    return left



def quicksort1(arr, left, right):
    if left >= right:
        return
    else:
        m = partition(arr, left, right)
        quicksort1(arr, left, m-1)
        quicksort1(arr, m, right)