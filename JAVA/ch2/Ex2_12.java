package JAVA.ch2;
public class Ex2_12 {
    public static void main(String args[]){
        String str = "3";

        System.out.println(str.charAt(0) -  '0'); // integer 3
        System.out.println(str.charAt(0) -  '0' + 1); // integer 4
        System.out.println(Integer.parseInt(str) - 1); // integer 4
        System.out.println("3" + 1); // String 31 ("3" + "1") 과 같음
        System.out.println(3 + '0'); // '0'은 숫자로 48 즉, 3 + 48 integer 51
        System.out.println((char)(3 + '0')); // 문자 '0'에 + 3 한 값을 char로 형변환 하면 '3'
    }
}
