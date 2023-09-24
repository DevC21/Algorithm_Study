public class PrintfEx1 {
    
    public static void main(String[] args){
        // System.out.println(10.0 / 3);

        // System.out.printf("%d\n", 15);  // 15
        // System.out.printf("%#o\n", 15); // 017
        // System.out.printf("%#x\n", 15); // 0xf
        // System.out.printf("%s\n", Integer.toBinaryString(15)); // 1111 (문자열)

        // double f = 123.456789;
        // System.out.printf("%f\n", f); // 123.456789  
        // System.out.printf("%e\n", f); // 1.234568e+02
        // System.out.printf("%g\n", f); // 123.457     

        // System.out.printf("[%5d]\n", 10); // [   10]
        // System.out.printf("[%-5d]\n", 10);// [10   ]
        // System.out.printf("[%05d]\n", 10);// [00010]

        double d = 1.23456789;
        // %전체자리.소수점아래자리
        //[  1.2345678900] 정수는 공백으로, 소숫점은 0으로 채워짐
        System.out.printf("d=%14.10f\n", d); 

        String url = "www.google.com";
        System.out.printf("[%s]\n", url);
        System.out.printf("[%20s]\n", url); // 20자리 공간을 확보하고 오른쪽 정렬
        System.out.printf("[%-20s]\n", url);// 20자리 공간을 확보하고 왼쪽 정렬
        System.out.printf("[%.10s]\n", url);// 앞쪽부터 10자리를 잘라서 출력
    }
}
