import java.util.Arrays;

public class Ex5_tmp_6 {
    public static void main(String[] args){
        int[] arr = {3, 2, 1, 0, 4}; // 1차원 배열 arr

        Arrays.sort(arr); // 배열 arr를 오름차순으로 정렬
        System.out.println(Arrays.toString(arr));

        int[][] arr2D = {{11, 12}, {21, 22}}; // 2차원 배열

        System.out.println(Arrays.toString(arr));
        System.out.println(Arrays.deepToString(arr2D));

        String[][] str2D = {{"aaa", "bbb"}, {"AAA", "BBB"}};
        String[][] str2D2 = {{"aaa", "bbb"}, {"AAA", "BBB"}};

        // 참조변수 값을 비교하는 동작이라서 올바르게 작동하지 않음
        // 두 배열이 같은 메모리 주소에 존재할 수 없다.
        // System.out.println(str2D == str2D2);
        System.out.println(Arrays.deepEquals(str2D, str2D2));

        int[] arr2 = Arrays.copyOf(arr, arr.length); // 0 1 2 3 4
        int[] arr3 = Arrays.copyOfRange(arr, 2, 4); // 2 3
        System.out.println(Arrays.toString(arr2));
        System.out.println(Arrays.toString(arr3));

    }    
}
