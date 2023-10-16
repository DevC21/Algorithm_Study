package JAVA.ch6;

public class Ex6_8 {
    public static void main(String[] args) {
		Data d = new Data();
		d.x = 10;

		Data d2 = copy(d);
		System.out.println("d.x = " + d.x);
		System.out.println("d2.x = " + d2.x);

	}

	static Data copy(Data d) { // 참조형 반환타입
		Data tmp = new Data();

        tmp.x = d.x;
		
        return tmp; // 복사한 객체의 주소를 반환한다.
	}
}
