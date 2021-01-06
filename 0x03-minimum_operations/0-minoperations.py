#!/usr/bin/python3
"""
This file calculates the minimum operation needed to copy and paste the same
string to accomplish a certain length
"""

counter = 0


def copy_all(text):
    """ Copies the input string

    Args:
        text (string): text to copy

    Returns:
        text (string): copied text
    """
    global counter
    copy = text[:]
    counter += 1
    return (copy)


def paste(text, copy):
    """ Paste copy into text

    Args:
        text (string): original text
        copy (string): copy text

    Returns:
        text (string): text with copy pasted
    """
    global counter
    counter += 1
    return (text + copy)


def minOperations(n):
    """Function to calculate the minimum operations needed.

    Considering that an initial text is given, and only copy_all and paste
    operations are possible, calculates the step to get into the desired length
    Args:
        n (int): Number that contains all the desired length of the string.

    Returns:
        int: The number of copy and paste needed to get into the solution.
    """
    global counter
    counter = 0
    text = "H"
    copy_buffer = ""
    if (type(n) != int or n <= 0):
        return (0)
    while (len(text) != n):
        if (len(text) == 1):
            copy_buffer = copy_all(text)
        elif ((len(text) < n) and n % (len(text)) == 0):
            copy_buffer = copy_all(text)
        text = paste(text, copy_buffer)
        if (len(text) > n):
            return (0)
    return (counter)
