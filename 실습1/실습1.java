package 실습과제1;

import java.util.Arrays;
import java.util.Scanner;

public class 실습1 {

	public static void main(String[] args) {
		// Scanner 객체 선언
		Scanner kbd = new Scanner(System.in);
		
		int num = kbd.nextInt();    // 데이터 개수
		int[] array = new int[num]; // 배열 선언
		
		// n개의 정수값 입력 받기
		for(int i=0; i<num; i++) {
			array[i] = kbd.nextInt();
		}
		
		//최댓값 최솟값 찾는 함수 호출
		int[] result = findMaxMin(num, array);
		
		//결과 출력
		System.out.println("\nn = "+num);
		System.out.println("data = "+Arrays.toString(array));

		System.out.println("\nMaximum = "+ result[0]);
		System.out.println("Minimum = "+ result[1]);
	}
	
	public static int[] findMaxMin(int num, int[] array) {		
		// 배열 원소 중 하나로 최대값, 최소값 초기화
		int max = array[0]; int min = array[0];
		
		
		// 최대값, 최소값 찾기
		for(int i=1; i<num; i++) {
			if(max<array[i]) {
				max = array[i];
			}
			
			if(min>array[i]) {
				min = array[i];
			}
		}
		
		// 리턴할 배열 초기화
		int[] result = new int[2];
		result[0] = max;
		result[1] = min;
		return result;
	}
}
