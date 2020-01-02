from test_framework import generic_test


def find_nearest_repetition(paragraph):
    table = dict()
    minimum = len(paragraph) + 1
    for index, word in enumerate(paragraph):
        if word in table:
            minimum = min(minimum, index - table[word])
        table[word] = index
    return -1 if minimum == len(paragraph) + 1 else minimum

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("nearest_repeated_entries.py",
                                       'nearest_repeated_entries.tsv',
                                       find_nearest_repetition))
