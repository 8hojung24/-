### 바이너리 트리병합
1. 바이너리 탐색 트리의 구조 정의
<img src="https://user-images.githubusercontent.com/67528774/203710246-bd129c92-cba6-411c-bd8a-4c6595eed05c.png" width="300" height="100"/>

2. 바이너리 탐색트리, 바이너리 탐색트리노드를 생성
<image src="https://user-images.githubusercontent.com/67528774/203710266-0783303c-6d15-4411-97e2-dcc83dcbc380.png" width="300" height="100"/>
<img src="https://user-images.githubusercontent.com/67528774/203710289-7e6f00d0-de9a-485b-90bc-b363837feb1c.png" width="300" height="100"/>

3. 바이너리 탐색트리에 값 추가
<img src="https://user-images.githubusercontent.com/67528774/203710310-ec0ff48f-1f80-4738-a752-c9e7199ee2e2.png" width="300" height="100"/>
getParentNode() 함수: 입력한 키 값과 트리의 키 값들을 비교해서 입력한 키값을 가질 노드의 부모노드를 포인터로 반환하고, 성공여부를 0과 1로 반환한다.
<img src="https://user-images.githubusercontent.com/67528774/203710333-d18263e6-db1f-474d-824a-da757fd08753.png" width="300" height="100"/>
insertNewBinSearchTreeNode() 함수: 바이너리트리에 새로운노드 추가
<img src="https://user-images.githubusercontent.com/67528774/203710347-1bb2ff9b-a9ac-4355-abf4-698f5096512f.png" width="300" height="100"/)

4. 바이너리트리, 노드 삭제
<img src="https://user-images.githubusercontent.com/67528774/203710376-ac89fa07-f194-4261-b9b4-350528510c0e.png" width="300" height="100"/>

5. readBinTree() 함수
“hw_input.txt”읽어서 바이너리트리 *pTree1, *pTree2에 저장, pTree1과 pTree2의 노드개수 *count1, *count2에 저장
<img src="https://user-images.githubusercontent.com/67528774/203710399-b211c59f-7977-4487-968e-d2adcbedd693.png" width="300" height="100"/>

6. 두개의 트리를 병합하여 mergeTree 만들기
바이너리트리 mergeTree 를 rootTree로 정의해서, rootTree의 루트노드가 mergeTree의 루트노드가 될 수 있도록 하고,insertTree는 재귀함수를 이용하여 모든 노드의 key값이 mergeTree에 추가되도록 하였다.
<img src="https://user-images.githubusercontent.com/67528774/203710412-529a2d34-77d1-429f-be69-8cc3a18ac1d2.png" width="300" height="100"/>

7. 추가된 엣지의 수 계산
searchWithParentNodeBST() 함수를 이용하여, mergeTree 노드의 부모 키값과, insertTree 노드의 부모 키값이 다르면 nNum을 하나씩 추가하였다. 
<img src="https://user-images.githubusercontent.com/67528774/203710426-3bb1fa67-b4bd-449f-806a-6a6115b7edac.png" width="300" height="100"/>
searchWithParentNodeBST() 함수
<img src="https://user-images.githubusercontent.com/67528774/203710437-80e44fe6-2109-454b-a94e-2516457c5b7c.png" width="300" height="100"/>

8. ”hw_output.txt” 파일 쓰기
<img src="https://user-images.githubusercontent.com/67528774/203710459-5446d66d-aa91-4532-87c7-c42c76a6051a.png" width="300" height="100"/>

9. main 함수
<img src="https://user-images.githubusercontent.com/67528774/203710506-fa0d9db0-cb04-49b5-b5a4-0d606be879b8.png" width="300" height="100"/>

### 과정
1. 파일을 읽어서 저장할 바이너리트리 pTree1, pTree2를 만들고, readBinTree()를 이용해 읽어온다.
2. 만약 pTree1 노드의 수가 pTree2 노드의 수보다 많으면, pTree1의 루트녿가 mergeTree의 루트노드가 될 수 있도록 하고, 추가된 엣지의 개수를 구한다.
3. 만약 pTree2 노드의 수가 pTree1 노드의 수보다 많으면, pTree2의 루트녿가 mergeTree의 루트노드가 될 수 있도록 하고, 추가된 엣지의개수를 구한다.
4. 삭제된 엣지(dNum)의 개수는 insertTree의 헤더노드를 제외하여 추가된 엣지의 개수(nNum)-1 이 된다.
5. mergeTree 와 nNum, dNum을 파일에 작성해준다.
6. 다 사용한 바이너리 트리를 제거한다.
