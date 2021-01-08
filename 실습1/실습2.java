package 실습과제1;

import java.util.Scanner;

public class 실습2 {

	public static void main(String[] args) {
		// Scanner 객체 선언
		Scanner kbd = new Scanner(System.in);
		
		// 행렬의 행, 열 숫자
		int n = kbd.nextInt(); //n값
		int m = kbd.nextInt(); //m값
		int l = kbd.nextInt(); //l값
		
		// 곱할 두 개의 행렬 A, B와 결과 행렬 C 선언
		int[][] A = new int[n][m];
		int[][] B = new int[m][l];
		int[][] C = new int[n][l];
		
		// 행렬 A 초기화
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				A[i][j] = kbd.nextInt();
			}
		}
		
		// 행렬 B 초기화
		for(int i=0; i<m; i++) {
			for(int j=0; j<l; j++) {
				B[i][j] = kbd.nextInt();
			}
		}
		
		// 행렬 C 초기화
		for(int i=0; i<n; i++) {
			for(int j=0; j<l; j++) {
				for(int k=0; k<m; k++) {
					C[i][j] += A[i][k]*B[k][j];
				}
			}
		}
		
		System.out.println();
		// 행렬 A 출력
		System.out.println("A =");
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				System.out.print(A[i][j]+"  ");
			}
			System.out.println();
		}
		
		System.out.println();
		// 행렬 B 출력
		System.out.println("B =");
		for(int i=0; i<m; i++) {
			for(int j=0; j<l; j++) {
				System.out.print(B[i][j]+"  ");
			}
			System.out.println();
		}
		
		System.out.println();
		// 행렬 C 출력
		System.out.println("C =");
		for(int i=0; i<n; i++) {
			for(int j=0; j<l; j++) {
				System.out.print(C[i][j]+"  ");
			}
			System.out.println();
		}

	}

}
