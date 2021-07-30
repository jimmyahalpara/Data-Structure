"""
Good morning! Here's your coding interview problem for today.

This problem was asked by Triplebyte.

Implement a data structure which carries out the following operations without resizing the underlying array:

add(value): Add a value to the set of values.
check(value): Check whether a value is in the set.
The check method may return occasional false positives (in other words, incorrectly identifying an element as part of the set), but should always correctly identify a true element.
"""

list = [None for i in range(10)]
pos = 0
leng = 10

def add(value):
    if pos >= leng:
        print("Arry full") 