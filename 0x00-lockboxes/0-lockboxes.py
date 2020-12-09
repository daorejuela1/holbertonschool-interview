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
    register = []
    boxChecking(boxes, 0, register)
    if len(register) == len(boxes):
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
    if key < len(boxes) and key not in register:
        register.append(key)
        for newkey in boxes[key]:
            boxChecking(boxes, newkey, register)
