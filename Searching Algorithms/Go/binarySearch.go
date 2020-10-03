// this program represents the Binary Search in Golang
package main
import "fmt"
 
func binarySearch(needle int, haystack []int) bool {
 
    low := 0
    high := len(haystack) - 1
 
    for low <= high{
        median := (low + high) / 2
 
        if haystack[median] < needle {
            low = median + 1
        }else{
            high = median - 1
        }
    }
 
    if low == len(haystack) || haystack[low] != needle {
        return false
    }
 
    return true
}
 
 
func main(){
	items := []int{1,2, 9, 20, 31, 45, 63, 70, 100}
	var findKey = 31

    if (binarySearch(findKey, items) == true){
		fmt.Println(findKey, "is in the array")
	}else{
		fmt.Println(findKey, "isn't available in the array")
	}
}