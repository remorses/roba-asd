from . import *


def test():
    x = mergesort([2, 3, 4, 5, 1])
    assert x == [1, 2, 3, 4, 5]