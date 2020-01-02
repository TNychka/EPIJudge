from test_framework import generic_test
from test_framework.test_failure import TestFailure
from collections import deque

class LruCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.lru = deque()
        self.dict = {}

    def _bump_isbn(self, isbn):
        self.lru.remove(isbn)
        self.lru.appendleft(isbn)

    def lookup(self, isbn):
        if isbn in self.dict:
            self._bump_isbn(isbn)
            return self.dict[isbn]
        return -1

    def insert(self, isbn, price):
        if isbn in self.dict:
            self._bump_isbn(isbn)
            return

        if len(self.lru) >= self.capacity:
            old_isbn = self.lru.pop()
            del self.dict[old_isbn]

        self.lru.appendleft(isbn)
        self.dict[isbn] = price

    def erase(self, isbn):
        if isbn not in self.dict:
            return False
        del self.dict[isbn]
        self.lru.remove(isbn)
        return True


def run_test(commands):
    if len(commands) < 1 or commands[0][0] != 'LruCache':
        raise RuntimeError('Expected LruCache as first command')

    cache = LruCache(commands[0][1])

    for cmd in commands[1:]:
        if cmd[0] == 'lookup':
            result = cache.lookup(cmd[1])
            if result != cmd[2]:
                raise TestFailure(
                    'Lookup: expected ' + str(cmd[2]) + ', got ' + str(result))
        elif cmd[0] == 'insert':
            cache.insert(cmd[1], cmd[2])
        elif cmd[0] == 'erase':
            result = 1 if cache.erase(cmd[1]) else 0
            if result != cmd[2]:
                raise TestFailure(
                    'Erase: expected ' + str(cmd[2]) + ', got ' + str(result))
        else:
            raise RuntimeError('Unexpected command ' + cmd[0])


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("lru_cache.py", 'lru_cache.tsv',
                                       run_test))
