# 실습 5-1  
## 스택(Stack)  
### 문제 정의  
* 최대 크기가 MAX_STACK_SIZE(= 5)인 배열을 이용하여 스택을 구현한다.  
즉, 배열 스택에 삽입하는 연산 push(), 삭제하여 출력하는 연산 pop(), 스택 top의 원소를 출력하는 연산 peek()을 구현하여 테스트한다.  
* Main 함수에서 아래의 예 1과 예 2의 push(), pop(), peek() 연산을 각각 차례대로 수행하여  
그 결과가 맞는지 출력하여 확인한 후 이미지를 캡처하여 제출한다.  

### Main 함수에서의 연산 순서의 예 1 (하나의 main함수에서 예1과 예2를 모두 수행함)  
* push(‘A’); peek(); push(‘B’); peek(); push(‘C’); peek(); push(‘D’), push(‘E’), push(‘F’); pop(); pop(); push(‘D’);  
peek(); push(‘E’); peek(); pop(); pop(); pop(); pop(); pop(); pop();  

### 출력 및 예 1(화면)  
* A B C “stack overflow” E D D E E D C B A “stack empty”  

### Main 함수에서의 연산 순서의 예 2  
* push(‘1’); pop(); push(‘2’); pop(); push(‘3’); pop();  
* push(‘1’); push(‘2’); pop(); pop(); push(‘3’); pop();  
* push(‘1’); pop(); push(‘2’); push(‘3’); pop(); pop();  
* push(‘1’); push(‘2’); pop(); push(‘3’); pop(); pop();  
* push(‘1’); push(‘2’); push(‘3’); pop(); pop(); pop();  

### 출력 및 예 2(화면)  
* 1 2 3  
* 2 1 3  
* 1 3 2  
* 2 3 1  
* 3 2 1  

### 참고사항  
* push(), pop(), peek() 함수의 호출과 출력은 메인 함수에서 담당해야함  
* **3 1 2 의 순서로 출력이 가능한지 생각해 본다.**

# 실습 5-2  
## 환형 큐(circular queue)  
### 문제 정의  
* 최대 크기가 MAX_QUEUE_SIZE(= 10)인 배열을 이용하여 환형 큐(circular queue)를 구현한다.  
즉, 환형 큐에 삽입하는 연산 enqueue(), 제거하여 출력하는 연산 dequeue(), 큐에서 다음에 제거할 원소를 출력하는 연산 peek()을 구현하여 테스트한다.  
* Main 함수에서 아래의 예 1과 예 2의 enqueue(), dequeue(), peek() 연산을 차례대로 수행하여 그 결과가 맞는지  
출력하여 확인한 후 이미지를 캡처하여 제출한다.  

### Main 함수에서의 연산 순서 예 1 (하나의 main함수에서 예1과 예2를 모두 수행함)  
* enqueue(‘A’); peek(); enqueue(‘B’); peek(); enqueue(‘C’); peek(); dequeue(); dequeue();  
enqueue(‘D’); peek(); enqueue(‘E’); peek(); dequeue(); dequeue(); dequeue(); dequeue();  

### 출력 및 예 1(화면)  
* A A A A B C C C D E “queue empty”  

### Main 함수에서의 연산 순서 예 2  
* enqueue(‘A’); dequeue(); enqueue(‘B’); dequeue(); enqueue(‘C’); dequeue(); dequeue();  
* enqueue(‘A’); enqueue(‘B’); enqueue(‘C’); enqueue(‘D’); enqueue(‘E’); enqueue(‘F’);  
enqueue(‘G’); enqueue(‘H’); enqueue(‘I’); dequeue(); peek(); enqueue(‘J’); enqueue(‘K’);  

### 출력 및 예 2(화면)  
* A B C “queue empty”  
* A B “queue overflow”  

### 참고사항  
* enqueue(), dequeue(), peek() 함수의 호출과 출력은 메인 함수에서 담당해야 함  
* 메인 함수에는 코멘트로 본인의 소속, 학번, 성명이 반드시 포함되어 있어야 함  
