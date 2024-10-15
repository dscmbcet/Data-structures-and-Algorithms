def heapify_max(arr, size, index):
    left = 2*index + 1
    right = 2*index + 2
    highest = index

    if left < size and arr[highest] < arr[left]:
        highest = left
    if right < size and arr[highest] < arr[right]:
        highest = right

    if highest != index:
        arr[highest], arr[index] = arr[index], arr[highest]
        heapify_max(arr, size, highest)

def heap_sort(arr):
    n = len(arr)
    for i in range(n//2 - 1, -1, -1):
        heapify_max(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify_max(arr, i, 0)

arr = [35, 33, 42, 10, 14, 19, 27, 44, 26, 31]
# heapify_max(arr, len(arr), 0)
# heap_sort(arr)
# print(arr)