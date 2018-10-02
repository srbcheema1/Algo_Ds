/**
 * Implements the BinarySearch algorithm.
 * Time Complexity: O(Log(N))
 *
 * @author Methusael Murmu
 */
public class BinarySearch {

    /**
     * Generic function that implements the binary search algorithm to return the
     * index of the first occurrence of the given search term in the provided array.
     * Returns -1 if the search term was not found.
     *
     * @param array The array of sorted values to search from
     * @param searchTerm The value to search for in the array
     * @return Index of the first occurrence of the search term within the array
     */
    public static <T extends Number> int search(final T[] array, T searchTerm) {
        // Trivial case
        if (array == null || array.length == 0 || searchTerm == null) {
            return -1;
        }

        int midIdx;
        int lowIdx = 0, highIdx = array.length - 1;

        while (lowIdx <= highIdx) {
            midIdx = (lowIdx + highIdx) / 2;

            // Evaluated values
            double sterm = searchTerm.doubleValue();
            double aterm = array[midIdx].doubleValue();

            if (aterm == sterm) {
                // Found a match, but we need to find the one with the smallest index
                if (midIdx == 0 || array[midIdx-1].doubleValue() != sterm) {
                    // This is the smallest index possible; found our search term at midIndex
                    return midIdx;
                }
            }

            if (aterm < sterm) {
                // Search term to the right; search upper half
                lowIdx = midIdx + 1;
            } else {
                // Search term to the left; search lower half
                highIdx = midIdx - 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int searchTerm = 5;
        Integer[] arr = { -1, 3, 3, 3, 5, 5, 5, 6, 6, 6, 8, 9, 10 };

        int index = BinarySearch.<Integer>search(arr, searchTerm);
        if (index != -1) {
            System.out.format("Found %d at index: %d\n", searchTerm, index);
        } else {
            System.out.format("Could not find %d in the array\n", searchTerm);
        }
    }
}
