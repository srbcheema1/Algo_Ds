import java.util.concurrent.CountDownLatch;

public class SleepSort {
    private static Thread Tread;

    public static void main(String[] args) {
        int[] nums = {0,1,2,3,4};
        sleepSort(nums);
    }

    public static void sleepSort(int[] nums){
        CountDownLatch completeSignal = new CountDownLatch(nums.length);
        for(int num : nums){
            new Thread(() -> {
                completeSignal.countDown();
                try{
                    //in order to make the sort more visible in console,
                    // factor of 1000 milliseconds is used.
                    completeSignal.await();
                    Tread.sleep(num * 1000);
                    System.out.println(num);
                }catch(InterruptedException e){
                    e.printStackTrace();
                }
            }).start();
        }
    }
}
