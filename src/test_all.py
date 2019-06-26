from . import *




def test_mergesort():
    x = mergesort([2, 3, 4, 5, 1])
    assert x == [1, 2, 3, 4, 5]
    x = mergesort([8, 2, 3, 4, 5, 1, 7, 6, 9, 0])
    assert x == [0,1,2,3,4,5,6,7,8,9]


def test_insertion():
    x = [2, 3, 4, 5, 1]
    insertionsort(x)
    assert x == [1, 2, 3, 4, 5]
    x = [8, 2, 3, 4, 5, 1, 7, 6, 9, 0]
    insertionsort(x)
    assert x == [0,1,2,3,4,5,6,7,8,9]

def test_selectionsort():
    x = [2, 3, 4, 5, 1]
    selectionsort(x)
    assert x == [1, 2, 3, 4, 5]
    x = [8, 2, 3, 4, 5, 1, 7, 6, 9, 0]
    selectionsort(x)
    assert x == [0,1,2,3,4,5,6,7,8,9]

def test_bubblesort():
    x = [2, 3, 4, 5, 1]
    bubblesort(x)
    assert x == [1, 2, 3, 4, 5]

def test_bubblesort2():
    x = [2, 3, 4, 5, 1]
    bubblesort2(x)
    assert x == [1, 2, 3, 4, 5]

def test_quicksort1():
    x = [2, 3, 4, 5, 1]
    quicksort1(x, 0, len(x) - 1)
    assert x == [1, 2, 3, 4, 5]


def test_bisect():
    x = list(range(20))
    i = 3
    assert bisect(x,  0, len(x) -1, x[i], ) == i
    assert bisect(x, 0, len(x) -1, 325235) == -1