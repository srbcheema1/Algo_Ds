from random import shuffle

# Sorting algorithm that relies solely on shuffling all
# numbers until the array is sorted. Worst case scenario
# is when it never sorts :(

def bogosort(my_array):
    pos = 0
    while True:
        if(pos == (len(my_array)-1)):
            break
        while (my_array[pos] > my_array[pos+1]):
            shuffle(my_array)
            pos = 0
        pos= 1)
    return my_array
