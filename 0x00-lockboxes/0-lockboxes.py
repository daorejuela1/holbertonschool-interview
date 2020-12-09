#!/usr/bin/python3
"""
This code solve the problem of lockbox by checking the state of every box
after traversing the keys
"""


def canUnlockAll(boxes):
    """
    Creates a register to know if the boxes are opened

    Args:
    boxes (list of list): List of boxes that contains the list of keys.
    Returns:
    True if all boxes can be opened, otherwise False
    """
    register = [0 for x in range(len(boxes))]
    boxChecking(boxes, 0, register)
    if all(register):
        return True
    return False


def boxChecking(boxes, key, register):
    """
    Opens a box and asks if the boxes are already opened

    Args:
    boxes (list of list): List of boxes that contains the list of keys.
    key: number of the box to be opened.
    register: list of boxes opened

    Returns:
    True if all boxes can be opened, otherwise False
    """
    if key < len(register) and register[key] != 1:
        register[key] = 1
        for newkey in boxes[key]:
            if newkey < len(register) and register[newkey] != 1:
                boxChecking(boxes, newkey, register)
