package JAVA.ch3;

class Ex3_2 {
    public static void main(String args[]){
        int i = 5, j = 0;

        j = i++; // 후위 증감 연산자
        System.out.println("i = " + i + " j = " + j); // i = 6 j = 5

        i = 5;
        j = 0;

        j = ++i; // 전위 증감 연산자
        System.out.println("i = " + i + " j = " + j); // i = 6 j = 6

    }    
    
}
