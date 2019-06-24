from . import *


def test_mergesort():
    x = mergesort([2, 3, 4, 5, 1])
    assert x == [1, 2, 3, 4, 5]

def test_insertion():
    x = [2, 3, 4, 5, 1]
    insertionsort(x)
    assert x == [1, 2, 3, 4, 5]