import java.util.Scanner;
/*
* @author Nikunj Khokhar
*/
public class SegmentTree {

    static int MAX = 1000005;
    static int arr[] ;
    static int tree[] ;
   public static void main(String args[])
   {
       Scanner sc = new Scanner(System.in);

       //Enter the value of the n which is the numner of element in the
       System.out.println("Enter the numbers of elements in Array : ");
       int n = sc.nextInt();
       arr = new int[MAX];
       tree = new int[MAX];



        System.out.println("Enter the Array elements :");
       for(int i=1;i<=n;i++)
       {
           arr[i] = sc.nextInt();
       }



       //Building the SegmentTree....
       build(1,1,n);


       //FInding the Minimum element between the range x to y......

       System.out.println("Enter the Range :");
       System.out.println("Enter the L : ");
       
       int x = sc.nextInt();
       System.out.println("Enter the R : ");
       int y = sc.nextInt();

       System.out.println("The Minimum element between the ranege " + x + "and "+ y +" :");
       System.out.println(query(1,1,n,x,y));



       //for updateing the Segment tree


       System.out.println("Enter the index which you want to change :");
       x = sc.nextInt();
       System.out.println("Enter the number :");
       y = sc.nextInt();

       //Update the value at x with y....
       update(1,1,n,x,y);



   }


    public static void build(int node, int start, int end)
    {
        if(start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(2*node, start, mid);
            build(2*node+1, mid+1, end);
            tree[node] = Math.min(tree[2*node],tree[2*node+1]);
        }
    }

    public static int query(int node, int start, int end, int l, int r)
    {
        if(r < start || end < l)
        {

            return MAX;
        }
        if(l <= start && end <= r)
        {

            return tree[node];
        }

        int mid = (start + end) / 2;
        int p1 = query(2*node, start, mid, l, r);
        int p2 = query(2*node+1, mid+1, end, l, r);
        return Math.min(p1,p2);
    }

    public static void update(int node, int start, int end, int idx, int val)
    {
        if(start == end)
        {
            // Leaf node
            arr[idx] = val;
            tree[node] = val;
        }
        else
        {
            int mid = (start + end) / 2;
            if(start <= idx && idx <= mid)
            {

                update(2*node, start, mid, idx, val);
            }
            else
            {

                update(2*node+1, mid+1, end, idx, val);
            }


            tree[node] = Math.min(tree[2*node], tree[2*node +1]);
        }
    }

}


