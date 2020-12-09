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
