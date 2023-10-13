package JAVA.ch6;

// 하나의 소스파일에는 하나의 클래스만 작성하는 것이 바람직하다.
public class Hello2 {
    public static void main(String[] args){
        System.out.println("Hello World!");
    }
} // 소스파일의 이름은 public class 이름과 일치해야함
// public class Hello3 {} // 하나의 소스파일에는 하나의 public class만 허용한다.
class Hello4 {} // public class가 없는 경우에는 소스파일의 이름은 클래스 이름중 하나와 일치하면 된다
class hello4 {} // 소스파일의 이름과 클래스는 대문자, 소문자를 구분한다.
