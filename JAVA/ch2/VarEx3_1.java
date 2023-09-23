public class VarEx3_1 {
    
    public static void main(String[] args){
        // score에 final을 붙여서 상수가 되므로 값 변경 불가
        final int score = 100;
        // score = 200;

        boolean power = true;

        byte b = 127; // -128 ~ 127;

        int oct = 010; // 8진수 , 10진수로 8
        int hex = 0x10; // 16진수, 10진수로 16

        long l = 10_000_000_000L;

        float f= 3.14f;
        double d = 3.14f; // float 타입 리터럴이어도 double이 더 넓은 범위이기때문에 대입 가능
        
        System.out.println(score);
        System.out.println(power);
        System.out.println(b);
        System.out.println(oct);
        System.out.println(hex);
        System.out.println(l);
        System.out.println(f);
        System.out.println(d);
        System.out.println(10.);
        System.out.println(.1);
        System.out.println(10f);
        System.out.println(1e3);
    }
}
