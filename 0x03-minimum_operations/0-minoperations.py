#!/usr/bin/python3
"""
This file calculates the minimum operation needed to copy and paste the same
string to accomplish a certain length
"""

counter = 0


def copy_all(text):
    """ Copies the input string

    Args:
        text (int): text to copy len

    Returns:
        text (int): copied text len
    """
    global counter
    counter += 1
    return (text)


def paste(text, copy):
    """ Paste copy into text

    Args:
        text (int): original text len
        copy (int): copy text len

    Returns:
        text (int): text with copy pasted
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
    text_len = 1
    copy_buffer = ""
    if (type(n) != int or n <= 0):
        return (0)
    while (text_len != n):
        if (n % (text_len) == 0):
            copy_buffer = copy_all(text_len)
        text_len = paste(text_len, copy_buffer)
    return (counter)
