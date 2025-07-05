/*
이진트리가 되기 위한 조건
1. 같은 값을 갖는 노드가 없어야 한다.
2. 왼쪽 서브트리에 있는 값은 현재 노드의 값보다 작고, 오른쪽 서브트리에 값은 현재 노드의 값보다 커야한다.
3. 서브트리도 이진트리여야 한다.

원소의 탐색, 추가, 삭제

- 탐색
  1) 탐색하려는 키 값이 루트 노드의 키값과 같은지 비교한다.

  2) 탐색하려는 키 값이 루트노드보다 키값이 작으면 왼쪽 서브트리로 이동한다.
     해당 서브트리에서 1을 행한다.

  3) 탐색하려는 키 값이 루트노드의 키값보다 크면 오른쪽 서브트리로
     이동하여 해당 서브트리에서 1을 행한다.

- 추가
    1) 탐색하려는 키 값이 이진탐색 트리에 존재하는지 탐색한다.
    2) 존재한다면 추가작업을 그만둔다.
    3) 존재하지 않는다면 탐색 실패가 발생한 현재위치에 원소를 추가한다.

-삭제
    1)삭제할 노드가 단말노드인 경우(차수 0)
        탐색하여 해당 노드를 찾는다
        해당노드를 삭제한다.
        해당 노드의 부모노드 링크를 null로 설정한다.

    2)삭제할 노드가 자식노드를 한 개 가진 경우(차수1)
        탐색하여 해당 노드를 찾는다.
        해당노드를 삭제한다.
        해당 노드의 자식노드를 해당 노드의 부모 노드의 링크에 연결한다.
    3)삭제할 노드가 자식노드를 두 개 가진 경우(차수2)
        해당 노드 삭제 후 해당노드의 부모노드와 링크될 자식노드를 선택해야 한다.
        삭제할 노드의 왼쪽 서브트리에서 가장 큰 자손 노드 또는 삭제할 오른쪽 서브트리에서 가장 작은 자손 노드를 선택하면된다.
*/
#include <iostream>
using namespace std;

struct BSNode {
    int Data = 0;

    BSNode* Left = nullptr;
    BSNode* Right = nullptr;
};

struct BSTree {
    BSNode* root = nullptr; //루트노드

    /*-탐색
        1) 탐색하려는 키 값이 루트 노드의 키값과 같은지 비교한다.

        2) 탐색하려는 키 값이 루트노드보다 키값이 작으면 왼쪽 서브트리로 이동한다.
        해당 서브트리에서 1을 행한다.

        3) 탐색하려는 키 값이 루트노드의 키값보다 크면 오른쪽 서브트리로
        이동하여 해당 서브트리에서 1을 행한다.*/
    BSNode* Search(BSNode* node, int x) {

        if (node == nullptr) return node;//null이며 그냥 반환

        //키 값이 루트노드의 키값보다 작으면 왼쪽노드로
        if (x < node->Data) {
            return Search(node->Left, x);
        }
        //키 값이 루트노드의 키값보다 크면 오른쪽 노드로
        else if (x > node->Data) {
            return Search(node->Right, x);
        }
        //키 값이랑 같은 값이면 해당 노드를 반환
        //else if(x == node->Data){
        else{
            return node;
        }
    }


    /*
    * - 추가
    1) 탐색하려는 키 값이 이진탐색 트리에 존재하는지 탐색한다.
    2) 존재한다면 추가작업을 그만둔다.
    3) 존재하지 않는다면 탐색 실패가 발생한 현재위치에 원소를 추가한다.
    */
    void InsertNode(int x) {
        BSNode* newNode = new BSNode();
        newNode->Data = x;

        //루트가 비어있으면 루트로 삽입
        if (root == nullptr) {
            root = newNode;
            return;
        }

        BSNode* InsertNode = root; //루트부터 시작해서 비어있는 자리를 찾는다.
        BSNode* InsertParentNode = nullptr; //삽입할 노드의 부모노드

        //삽입할 노드와 그의 부모노드를 찾는다.
        while (InsertNode != nullptr) {
            InsertParentNode = InsertNode;
            if (x < InsertNode->Data) {
                InsertNode = InsertNode->Left;
            }
            else if (x > InsertNode->Data) {
                InsertNode = InsertNode->Right;
            }
            else { //이미 값이 있음.
                delete InsertNode;
                return;
            }
        }
        
        //삽입
        if (x < InsertParentNode->Data) {
            InsertParentNode->Left = newNode;
        }
        else {
            InsertParentNode->Right = newNode;
        }
        
    }

    /*
    -삭제
    1)삭제할 노드가 단말노드인 경우(차수 0)
        탐색하여 해당 노드를 찾는다
        해당노드를 삭제한다.
        해당 노드의 부모노드 링크를 null로 설정한다.

    2)삭제할 노드가 자식노드를 한 개 가진 경우(차수1)
        탐색하여 해당 노드를 찾는다.
        해당노드를 삭제한다.
        해당 노드의 자식노드를 해당 노드의 부모 노드의 링크에 연결한다.
    3)삭제할 노드가 자식노드를 두 개 가진 경우(차수2)
        해당 노드 삭제 후 해당노드의 부모노드와 링크될 자식노드를 선택해야 한다.
        삭제할 노드의 왼쪽 서브트리에서 가장 큰 자손 노드 또는 삭제할 오른쪽 서브트리에서 가장 작은 자손 노드를 선택하면된다.
    */
    void Delete(int x) 
    {
        //삭제할 노드 탐색
        BSNode* delNode = root; //삭제할 노드
        BSNode* delParentNode = nullptr;//삭제할 노드의 부모노드

        //삭제할 노드의 부모노드를 찾는다. (삭제노드가 null이 아니고 x값과 같지 않을동안 반복)
        while (delNode != nullptr && delNode->Data!=x) 
        {
            delParentNode = delNode; //조건문에 일치하면 나가기 때문에 매번 갱신하며 삭제노드의 부모를 찾는다.

            if (x < delNode->Data) //키 값보다 작으면 왼쪽으로
            { 
                delNode = delNode->Left;
            }
            else if (x > delNode->Data) //키 값보다 크면 오른쪽으로
            { 
                delNode = delNode->Right;
            }
        }

        //삭제 실패
        if (delNode == nullptr) {
            cout << "삭제할 노드가 없습니다." << endl;
            return;
        }
        


        //삭제 성공
        //Case 0: 단말노드일 경우(Left Right둘다 nullptr일 경우)
        if (delNode->Left == nullptr && delNode->Right == nullptr) {
            if (delParentNode != nullptr) //부모가 null인지도 검사
            {
                if (delParentNode->Left == delNode) //부모노드의 왼쪽자식노드를 nullptr로
                {
                    delParentNode->Left = nullptr;
                }
                else if(delParentNode->Right == delNode) //부모노드의 오른쪽 자식을 nullptr로
                {
                    delParentNode->Right = nullptr;
                }
            }
        }

        //Case 1: 자식이 하나인 경우(둘중 하나라도 자식노드가 1개일 경우)
        else if ((delNode->Left == nullptr && delNode->Right != nullptr) ||
            (delNode->Left != nullptr && delNode->Right == nullptr)) 
        {
            BSNode* child = nullptr; //자식이 될 노드

            //1. 삭제노드의 자식노드를 child에 임시저장한다.
            if (delNode->Left != nullptr) {
                child = delNode->Left; //삭제노드(delNode)의 왼쪽자식으로 설정
            }
            else {
                child = delNode->Right; //삭제노드(delNode)의 오른쪽자식으로 설정
            }

            //2. 삭제노드부모(delParentNode)에 해당 자식을 링크시킨다. 
            // 해당 자식을 할아버지노드에 연결하는 꼴
            if (delParentNode != nullptr) {
                if (delParentNode->Left == delNode) //삭제노드부모의 왼쪽자식이 삭제노드일경우 거기에 링크
                {
                    delParentNode->Left = child;
                }
                else //삭제노드부모의 오른쪽자식이 삭제노드일경우 거기에 링크
                {
                    delParentNode->Right = child;
                }
            }
            else //삭제노드부모가 null일 경우(삭제노드의 부모가 없다는 것은 루트노드란 뜻.) 
            {
                root = child;
            }
        }

        //Case 2: 삭제할 노드가 자식노드를 둘 다 가진 경우
        else 
        {
            //1. 왼쪽 자식노드에서 가장 큰 값의 노드와 그의 부모노드를 찾는다.
            BSNode* MaxNode = delNode->Left; //왼쪽 노드를 설정
            BSNode* MaxParentNode = delNode;
            //왼쪽 서브트리에서 가장 큰 값(가장 오른쪽 하단에 있는 것)
            while (MaxNode->Right != nullptr) 
            { //오른쪽 노드가 없을때 까지 반복
                MaxParentNode = MaxNode; //오른쪽 설정전 노드를 부모노드로 설정
                MaxNode = MaxNode->Right; //가장 큰값의 노드를 오른쪽 노드로 설정
            }

            //2. 가장 큰 노드(MaxNode)를 원래 자리에서 제거
            if (MaxParentNode->Left == MaxNode) 
            {
                MaxParentNode->Left = MaxNode->Left;
            }
            else 
            {
                MaxParentNode->Right = MaxNode->Left;
            }
            
            //3. MaxNode를 delNode자리로 올림(delNode를 MaxNode로 뒤집어 쓴다 생각)
            MaxNode->Left = delNode->Left;
            MaxNode->Right = delNode->Right;

            //4. 삭제할 부모노드의 자식을 MaxNode로 재링크 한다.
            //삭제할 노드가 루트면 루트를 MaxNode로 설정
            if (delNode == root) 
            {
                root = MaxNode;
            }
            else 
            {   //삭제할부모노드의 왼쪽이 삭제할 노드면 삭제할 노드에 가장 큰 값을 붙인다.
                //기존 delNode의 자리를 MaxNode가 들어가는 것
                if (delParentNode->Left == delNode) 
                {
                    delParentNode->Left = MaxNode;
                }
                else 
                {
                    delParentNode->Right = MaxNode;
                }
            }
        }

        delete delNode; //삭제할 노드를 동적할당 해제.
    }

    //중위순회로 출력
    void InOrder(BSNode* node)
    {
        if (node == nullptr) return;
        InOrder(node->Left);
        cout << node->Data << " ";
        InOrder(node->Right);
    }
};


int main()
{
    BSTree tree;

    // [1] 삽입 테스트
    tree.InsertNode(50);
    tree.InsertNode(30);
    tree.InsertNode(70);
    tree.InsertNode(20);
    tree.InsertNode(40);
    tree.InsertNode(60);
    tree.InsertNode(80);

    cout << "[삽입 후 중위순회] : ";
    tree.InOrder(tree.root);
    cout << "\n";

    // [2] 탐색 테스트
    BSNode* found = tree.Search(tree.root, 40);
    if (found) cout << "탐색 성공: " << found->Data << "\n";
    else cout << "탐색 실패: 40\n";

    found = tree.Search(tree.root, 99);
    if (found) cout << "탐색 성공: " << found->Data << "\n";
    else cout << "탐색 실패: 99\n";

    // [3] 삭제 테스트
    tree.Delete(20);  // Case 0: 리프노드
    tree.Delete(30);  // Case 1: 왼쪽 자식만 있는 노드
    tree.Delete(50);  // Case 2: 자식 2개 가진 루트 노드

    cout << "[삭제 후 중위순회] : ";
    tree.InOrder(tree.root);
    cout << "\n";

    return 0;
}

