from test_framework import generic_test


# The numbering starts from one, i.e., if A = [3, 1, -1, 2]
# find_kth_largest(1, A) returns 3, find_kth_largest(2, A) returns 2,
# find_kth_largest(3, A) returns 1, and find_kth_largest(4, A) returns -1.
def find_kth_largest(k, A):
    if k > len(A):
        return -1
    start = 0
    end = len(A) - 1
    while start < end:
        i = start
        j = end
        pivot = A[end]
        while i < j:
            if A[i] < pivot:
                i += 1
            elif A[j] >= pivot:
                j -= 1
            else:
                A[i], A[j] = A[j], A[i]
        if A[i] >= pivot:
            A[i], A[end] = A[end], A[i]
        else:
            A[i + 1], A[end] = A[end], A[i + 1]

        if i == len(A) - k:
            return A[i]
        elif i < len(A) - k:
            start = i + 1
        else:
            end = i - 1
    return A[end]


if __name__ == '__main__':
    exit(generic_test.generic_test_main("kth_largest_in_array.py",
                                       'kth_largest_in_array.tsv',
                                       find_kth_largest))
