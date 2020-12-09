#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import doctest
import unittest

canUnlockAll = __import__('0-lockboxes').canUnlockAll

class TestLockBoxes(unittest.TestCase):
    """Unittest."""
    def test_empty(self):
        boxes = [[]]
        self.assertEqual(canUnlockAll(boxes), True)

    def test_sequence(self):
        boxes = [[1], [2], [3], [4], []]
        self.assertEqual(canUnlockAll(boxes), True)

    def test_multiple(self):
        boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
        self.assertEqual(canUnlockAll(boxes), False)

    def test_fake(self):
        boxes = [[1], [0], [3], []]
        self.assertEqual(canUnlockAll(boxes), False)

    def test_multiplepath(self):
        boxes = [[1, 2, 3], [0], [3], []]
        self.assertEqual(canUnlockAll(boxes), True)

    def test_multiplepath_false(self):
        boxes = [[1], [1, 2, 0], [0], []]
        self.assertEqual(canUnlockAll(boxes), False)

    def test_multiplepath_true(self):
        boxes = [[1], [1, 2, 0], [3], []]
        self.assertEqual(canUnlockAll(boxes), True)

    def test_oneforall(self):
        boxes = [[1, 3], [], [], [2]]
        self.assertEqual(canUnlockAll(boxes), True)

    def test_lastopenall(self):
        boxes = [[3], [], [], [1, 2]]
        self.assertEqual(canUnlockAll(boxes), True)

    def test_nopen(self):
        boxes = [[3], [], [], []]
        self.assertEqual(canUnlockAll(boxes), False)

    def test_nopen2(self):
        boxes = [[], [], [], []]
        self.assertEqual(canUnlockAll(boxes), False)

    def test_nopen2(self):
        boxes = [[1], [2], [], []]
        self.assertEqual(canUnlockAll(boxes), False)

    def test_loops(self):
        boxes = [[0, 1, 2], [0, 1, 2], [0, 1, 2, 3], [0]]
        self.assertEqual(canUnlockAll(boxes), True)

    def test_loops2(self):
        boxes = [[0, 1, 2], [0, 1, 2, 3], [0, 1, 2, 3], [0], []]
        self.assertEqual(canUnlockAll(boxes), False)

    def test_weirdkey(self):
        boxes = [[0, 1, 2], [0, 1, 2, 3, 8], [0, 1, 2, 3, 4], [0], []]
        self.assertEqual(canUnlockAll(boxes), True)
