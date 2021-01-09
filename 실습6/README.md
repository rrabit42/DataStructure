# 실습 6  
## 이진트리의 운행(binary tree traversal)  
### 문제 정의  
* Main() 함수에서 아래 (예 1)과 같은 간단한 수식표현트리를 연결리스트로 만들고,  
* 이 수식표현트리에 대해 각각 중순위(inorder), 후순위(postorder), 전순위(preorder) 운행을 재귀적으로 수행하여 중순위(infix) 표기, 전순위(prefix) 표기 및 후순위(postfix) 표기 결과를 출력한다.  
* 또한 2쪽에서 기술한 운행 알고리즘인 triple_order()의 결과에 대해서도 출력하고 맞는지 확인한다.  
* (예 1) 및 강의노트 11쪽의 일반 이진트리 등 두가지 경우에 대해 각각 테스트하여 제출한다.  

### 수식표현트리 구성 (예 1)  
```
TreeNode n1={'a', NULL, NULL};  
TreeNode n2={'b', NULL, NULL};  
TreeNode n3={'*', &n1, &n2};  
TreeNode n4={'c', NULL, NULL};  
TreeNode n5={'d', NULL, NULL};  
TreeNode n6={'/', &n4, &n5};  
TreeNode n7={'+', &n3, &n6};  
TreeNode *exp= &n7;  
```

### 알고리즘 triple_order(x)  
```
if x ≠ NULL
then print DATA(x)
triple_order(LEFT(x))
print DATA(x)
triple_order(RIGHT(x))
print DATA(x)
```

### 참고사항  
* 수식표현트리의 구성, 함수 preorder(), inorder(), postorder(), triple_order()의 호출은 메인 함수에서 담당해야 함  
* 메인 함수에는 코멘트로 본인의 소속, 학번, 성명이 반드시 포함되어 있어야 함  
