package JAVA.ch3;

public class Ex3_11 {
    public static void main(String[] args){
        double pi = 3.141592;
        // Math.round는 소수점 첫째자리에서 반올림한 정수를 반환 한다.
        double shortPi = Math.round(pi * 1000) / 1000.0;
        // Math.round(3.141592 * 1000) / 1000.0
        // Math.round(3142.592) / 1000.0
        // 3142 / 1000.0
        // 3.142

        // 3.141 로 변환하려면
        System.out.println((int)(pi * 1000) / 1000.0);

        System.out.println(shortPi); // 3.142
    }
}
