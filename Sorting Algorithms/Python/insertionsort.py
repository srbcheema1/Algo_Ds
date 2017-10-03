def insertion_sort(my_array):
    ordered_array = []
    for pos in range(len(my_array)):
        new_pos = pos
        while(new_pos > 0 and (my_array[new_pos] < my_array[new_pos-1])):
            temp = my_array[new_pos]
            my_array[new_pos] = my_array[new_pos-1]
            my_array[new_pos-1] = temp
            new_pos -= 1
    return my_array
