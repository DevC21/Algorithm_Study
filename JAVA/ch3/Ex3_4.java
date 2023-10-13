package JAVA.ch3;

public class Ex3_4 {
    public static void main(String[] args){

        // 부호 연산자
        // '-'는 피연산자의 부호를 반대로 변경
        // '+'는 아무런 일도 하지 않는다.(실제로 사용 X)
        int i = -10;
        i = +i;
        System.out.println(i); // -10

        i = -10;
        i = -1;
        System.out.println(i); // 10
    }
}
