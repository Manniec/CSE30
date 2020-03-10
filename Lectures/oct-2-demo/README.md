Introduction
============

So far in the class we have seen an example of how the choice of data structures
can have a significant impact on the performance of our applications. In the Word
Game, where we were finding all possible words that can be made from a collection
of 9 characters, we solved the problem by generating all possible permutations of
all possible substrings, and checked each one of these permutations to see which
of them is a valid word. For our game, we have 9 letters, so there are up to
roughly a million different permutations. (This number goes down if there are
repeated characters).

This means that, we need to process up to 1 million strings in order to display a
solution. We saw that when the set of valid English words was stored as a C++ vector
(which is equivalent to an array list in Java), checking a million strings for
validity was incredibly slow. When we changed our storage mechanism (the data structure)
from a vector to a hashmap, without changing the logic of our checkWord function,
we experienced massive improvements in performance. In the case of a vector, a regular
computer would have needed days in order to complete the task, whereas with a hashmap
the same computer finished in less than 1 second.

How is all this possible? Today, we start exploring what's under the hood of these
data structures, so we can understand how they work, and how we can draw inspiration
from some of them to build data structures of our own.