import java.util.Arrays; // VSCODE 자동 import키는 Alt + Shift + O

public class Ex5_tmp_3 {
    public static void main(String[] args){
        int[] iArr = {100, 95, 80, 70, 60}; // 길이가 5인 int 배열

        for(int i = 0; i < iArr.length; i++){
            System.out.println(iArr[i]);
        }

        System.out.println(Arrays.toString(iArr));
    }
}
