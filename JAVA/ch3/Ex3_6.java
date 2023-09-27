public class Ex3_6 {
    public static void main(String args[]) { 
		int a = 10;
		int b = 4;

		System.out.printf("%d + %d = %d\n",  a, b, a + b); // 10 + 4 = 14
		System.out.printf("%d - %d = %d\n",  a, b, a - b); // 10 - 4 = 6
		System.out.printf("%d * %d = %d\n",  a, b, a * b); // 10 * 4 = 40
		System.out.printf("%d / %d = %d\n",  a, b, a / b); // 10 / 4 = 2 -> 정수끼리의 나눗셈은 소숫점은 버려짐
		System.out.printf("%d / %f = %f\n",  a, (float)b, a / (float)b); // 10 / 4.0 = 2.5
        // 두 피연산자의 타입을 같게 일치시킨다. (보다 큰 타입으로 일치)

	}
}
