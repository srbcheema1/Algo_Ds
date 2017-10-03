def bubble_sort(arr):
    changed = True
    while changed:
        changed = False
        for i in range(len(arr) - 1):
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
                changed = True
    return None
