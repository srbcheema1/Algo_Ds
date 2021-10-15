import java.util.ArrayList;
import java.util.concurrent.CountDownLatch;

public class SleepSort {
    //Sleep sort puts each element of an integer array into sleep at the same time
    // due to the value differences, the smaller value would "wake up" first hence added to
    // the array first and so on.
    private static Thread Tread;

    public static void main(String[] args) {
        int[] nums = {0,1,2,3,4};
        sleepSort(nums);
    }

    public static void sleepSort(int[] nums){
        CountDownLatch completeSignal = new CountDownLatch(nums.length);
        ArrayList<Integer> sortedNums = new ArrayList<>();
        for(int i = 0; i<nums.length; i++){
            int finalI = i;
            new Thread(new Runnable() {
                @Override
                public void run() {
                    completeSignal.countDown();
                    try {
                        completeSignal.await();
                        //In order to make the sort more visible in console,
                        // factor of 1000 milliseconds is applied.
                        Tread.sleep(nums[finalI] * 1000);
                        sortedNums.add(nums[finalI]);
                        System.out.println("Current sorted nums: " + sortedNums.toString());
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }).start();
        }
    }
}
