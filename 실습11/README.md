# 실습 11  
## 방향그래프에서 최단경로(shortest paths) 구하기
### 문제 정의  
* 입력 파일로부터 방향 그래프의 정점의 개수(n), 에지의 개수(m), m개의 방향 에지 및 가중치를 입력받아  
그래프를 가중치 인접 행렬(weighted adjacency matrix)로 구성한다.  
* 주어지는 입력 파일은 “sp1.txt”, “sp2.txt”, “sp3.txt”이며,  
각 파일의 첫 줄에는 n과 m, 두번째 줄부터는 m개의 줄이 각 줄마다 방향 에지와 가중치로 구성되어 있다. (단, n은 최대 20개, m은 최대 200개)  
* 위에서 구성한 가중치 인접 행렬을 이용하여 시작 정점 v0부터 모든 정점까지의 최단 경로(shortest paths)를  
Dijkstra의 알고리즘에 의해 구한다. (Lecture 10. 그래프(part 2)의 19~20쪽 참조)  

### 입출력의 예(각 파일 별로 결과를 출력함)  
* 입력 파일(“sp1.txt”)  
```
6 9 /* n=6, m=9
0 1 2 /* 방향 에지 <v0, v1>, 가중치 2
0 2 4 /* 방향 에지 <v0, v2>, 가중치 4
1 2 1
1 3 4
1 4 2 /* …
2 4 2
3 5 2
4 3 3
4 5 2 /* 방향 에지 <v4, v5>, 가중치 2
```
* 출력  
```
입력 파일 = “sp1.txt”
v0로부터의 최단경로 : 0 2 3 6 4 6 /* 차례대로 v0, v1, v2, v3, v4, v5까지의 거리임
```  

### 참고사항  
* 입력 파일에 대한 가중치 인접 행렬의 구성은 메인 함수에서 작성하고,  
최단경로를 구하는 함수는 따로 작성하여 메인 함수에서 호출하도록 한다.  
* 메인 함수에는 주석(comment)으로 본인의 소속, 학번, 성명이 반드시 포함되어 있어야 함  
