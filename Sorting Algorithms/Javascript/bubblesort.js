//function takes in array
const bubblesort = (array) => {
  let length = array.length;
  
 
  for (let i=0;i<length-1;i++){
    //no need to check last value of previous loop
    for (let j=0;j<(length-i-1);j++){
      //compare adjacent values
      if (array[j] > array[j+1]){
        //do the swap
        let temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      } 
    }
  }
  
  return array;
}

//test array
console.log(bubblesort([3,17,24,4,5,1,4,2,3]));