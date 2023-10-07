public class Ex5_tmp_2 {
    public static void main(String[] args){
        int[] arr = new int[10]; // 배열의 선언과 생성을 동시에
        System.out.println("arr.length = " + arr.length);

        for(int i = 0; i < arr.length; i++){
            arr[i] = i * 10 + 50;
            System.out.println("arr["+i+"] = " + arr[i]);
        }
    }    
}
