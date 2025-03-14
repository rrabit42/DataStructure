# 실습 7  
## 이진탐색트리의 구성 및 이진트리의 연산들  
### 문제 정의  
* 입력되는 데이터의 개수 및 데이터가 차례로 입력될 때 비어있는 이진트리부터 연결리스트를 사용하여 이진탐색트리를 구성한다.  
* 새로운 데이터(노드)가 삽입될 때마다 구성된 이진탐색트리의 노드 개수와 높이를 각각 구하고 중순위 운행을 하여 그 결과를 확인한다.  
* 입력의 순서를 달리해서 2개의 예에 대해 각각 수행한 결과를 제출한다. (아래의 예 포함)  

### 입출력의 예 (데이터 입력의 순서가 50, 25, 30, 57, 70, 10 일 때)  
1. 입력  
```
6 // # of data, 첫번째 줄은 입력되는 데이터의 개수
50 // 1st data, 두번째 줄부터 데이터를 하나씩 입력하여 결과를 출력
```
2. 출력  
* 노드 개수 = 1  
* 높이 = 0  
* 중순위 운행 = 50  

### 입출력의 예 (계속)  
```
2. … 3. … 4. … 5. … (생략)
6. 입력
10 // 6th data  
```
출력
* 노드 개수 = 6  
* 높이 = 2  
* 중순위 운행 = 10 25 30 50 57 70  

### 참고사항  
* 이진탐색트리의 구성을 위한 노드 삽입 함수(insert_node), 중순위 운행 함수(inorder),  
노드 개수를 구하는 함수(get_node_count), 높이를 구하는 함수(get_height)의 호출은 메인 함수에서 담당해야 함  
* 메인 함수에는 코멘트로 본인의 소속, 학번, 성명이 반드시 포함되어 있어야 함  
