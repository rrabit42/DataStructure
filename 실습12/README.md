# 실습 12  
## 이진 탐색과 보간 탐색
### 문제 정의
* 정렬된 n개의 데이터가 배열에 저장되어 있을 때 주어진 키(key) 값의 위치(인덱스)를 찾는 이진 탐색 프로그램과 보간 탐색 프로그램을  
for문 또는 while문 등의 반복문을 사용하여 작성하라. 만약 해당 키값이 없을 때는 키값의 위치로 -1을 반환한다.  
* 키값이 없는 경우를 2번 포함하여 적어도 5번 이상 키값을 변화시켜 가면서 테스트하여 결과를 출력한다.  

### 입력(반드시 프로그램상에서 할 것)  
* 배열 크기가 10,000인 일차원 배열을 선언함.  
* 배열 인덱스 i에는 원소값으로 (i+1)번째 소수를 저장함. 즉, 배열 인덱스 0부터 9,999까지 정수값 2, 3, 5, 7, 11, … , 104,723, 104,729 가 저장되어 있음  

### 출력 및 예 (화면)  
* 주어지는 키값  
* 이진 탐색에 의한 키값의 위치(인덱스) 및 비교 회수  
* 보간 탐색에 의한 키값의 위치(인덱스) 및 비교 회수  

### 참고사항  
* 배열의 원소값 생성을 위한 함수 prime_generate()는 각자가 작성함  
* 함수 호출 및 출력은 메인 함수에서 담당함  
* 메인 함수에는 코멘트로 본인의 학번, 소속, 성명이 포함되어야 함  
