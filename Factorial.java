import java.math.BigInteger;
import java.util.Scanner;
public class Main
{
  static BigInteger fact(int n)
  {
    BigInteger b=new BigInteger("1");
    for(int i=2;i<=n;i++)
    {
    b=b.multiply(BigInteger.valueOf(i));
    }
    return b;
  }
  public static void main(String args[])
  {
  int n;
  Scanner scan=new Scanner(System.in);
  n=scan.nextInt();
  System.out.println(fact(n));
  }
 }
