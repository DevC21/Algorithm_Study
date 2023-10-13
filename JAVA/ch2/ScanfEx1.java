package JAVA.ch2;
import java.util.*;

public class ScanfEx1 {
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();
        int num2 = sc.nextInt();
        System.out.println(num);
        System.out.println(num2);

        String input = sc.nextLine();
        int num3 = Integer.parseInt(input);

        System.out.println(num3);

        sc.close();
    }
}
