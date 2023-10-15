package JAVA.ch6;

public class Ex6_4 {
    public static void main(String args[]) {
        MyMath mm = new MyMath();
        long result_max = mm.max(5L, 3L);
        long result_min = mm.min(5L, 3L);
        long result1 = mm.add(5L, 3L);
        long result2 = mm.subtract(5L, 3L);
        long result3 = mm.multiply(5L, 3L);
        double result4 = mm.divide(5L, 3L);

        System.out.println("max(5L, 3L) = "      + result_max);
        System.out.println("min(5L, 3L) = "      + result_min);
        System.out.println("add(5L, 3L) = "      + result1);
        System.out.println("subtract(5L, 3L) = " + result2);
        System.out.println("multiply(5L, 3L) = " + result3);
        System.out.println("divide(5L, 3L) = "   + result4);
    }
}

class MyMath {
    long add(long a, long b) {
        long result = a+b;
        return result;
    //	return a + b;	// 위의 두 줄을 이와 같이 한 줄로 간단히 할 수 있다.
    }

    // 두 값을 받아서 둘중에 큰 값을 반환하는 메서드를 작성하시오.
    long max(long a, long b) {
        // if(a > b)
        //     return a;
        // else
        //     return b;
        
        // 3항 연산자 
        return a > b ? a : b;
    }

    long min(long a, long b) {
        // if(a < b)
        //     return a;
        // else
        //     return b;
        
        // 3항 연산자 
        return a < b ? a : b;
    }

    long subtract(long a, long b) { return a - b; }

    long multiply(long a, long b) { return a * b; }

    double divide(double a, double b) { return a / b; }
}