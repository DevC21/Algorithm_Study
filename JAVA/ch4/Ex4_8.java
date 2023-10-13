package JAVA.ch4;

public class Ex4_8 {
    public static void main(String[] args){

        for(int i = 1, j = 10; i <= 10; i++, j--)
            System.out.printf("%d \t %d%n", i, j);

        int i = 1; // scope(범위) - 선언위치부터 선언된 블럭의 끝까지
        // 조건식을 생략하면, true로 간주되어서 무한반복문이 된다
        for(;;)
            System.out.println("i=" + i);
        
    }

}
