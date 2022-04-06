#!/usr/bin/python3
"""
Maria and Ben are playing a game. Given a set of consecutive integers
starting from 1 up to and including n, they take turns choosing a prime number
from the set and removing that number and its multiples from the set.
The player that cannot make a move loses the game.
"""


def isWinner(x, nums):
    """ Detects the winner in the Prime Game"""
    if x <= 0 or not nums:
        return None

    n = max(nums)
    deck = [True for x in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not deck[i]:
            continue
        for j in range(i*i, n + 1, i):
            deck[j] = False

    deck[0] = deck[1] = False
    c = 0
    for i in range(len(deck)):
        if deck[i]:
            c += 1
        deck[i] = c

    player1 = 0
    for n in nums:
        player1 += deck[n] % 2 == 1
    if player1 * 2 > len(nums):
        return "Maria"
    if player1 * 2 == len(nums):
        return None
    return "Ben"
