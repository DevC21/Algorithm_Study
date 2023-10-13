package JAVA.ch3;

public class Ex3_9 {
    public static void main(String[] args){
        int a = 1_000_000; // 10ÀÇ 6Á¦°ö
        int b = 2_000_000; // 10ÀÇ 6Á¦°ö * 2

        // 10ÀÇ 12Á¦°ö intÀÇ ¹üÀ§´Â 10ÀÇ 9Á¦°ö
        long c = (long)a * b; // a * b = 2,000,000,000,000

        System.out.println(c);
    }
}
