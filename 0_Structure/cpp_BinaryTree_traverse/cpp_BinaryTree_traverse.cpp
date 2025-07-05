/*
이진 트리(Binary Tree)
=> 탐색용 자료구조

 1:N의 비선형 자료구조: 
 1개가 여러개와 연결되며 데이터가 일렬(선형)으로 나열되지 않고 가지를 치거나 계층구조처럼 생긴 구조

 1)트리여야한다.
 2)최대 자식노드 갯수 <=2
 3)왼쪽자식노드 or 오른쪽 자식노드

 이진 트리의 순회
 순회 traverse: 모든 노드를 중복없이 한번씩 방문하는 것.

 전위순회 (Pre)Order Traverse
 => 루트노드->왼쪽자식->오른쪽자식

 중위순회 (In)order Traverse
 => 왼쪽자식-> 루트노드 -> 오른쪽자식

 후위순회 (Post)Order Traverse
 => 왼쪽자식-> 오른쪽자식-> 루트노드

 층별순회 (level)Order Traverse
 => 위에서 아래로 층별로 탐색
*/
#include <iostream>
#include <queue>
using namespace std;

struct BNode {
    char Data;

    BNode* Left = nullptr; //왼쪽노드
    BNode* Right = nullptr; //오른쪽노드
};

struct BinaryTree {
    BNode* rootNode = nullptr;

    queue<BNode*> Level; //BNode보다 포인터변수로 메모리를 최소화

    BNode* CreateNode(char data) {
        BNode* newNode = new BNode();
        newNode->Data = data;
        return newNode;
    }

    void BuildCustomTree() {
        rootNode = CreateNode('C');
        rootNode->Left = CreateNode('B');
        rootNode->Left->Left = CreateNode('A');
        rootNode->Right = CreateNode('D');
        rootNode->Right->Right = CreateNode('E');
        rootNode->Right->Right->Right = CreateNode('F');
        rootNode->Right->Right->Right->Right = CreateNode('G');

    }

    //원래 삽입
    BNode* Insert(BNode* root , char x) {
        //루트가 없으면 루트노드로 설정하고 리턴.
        if (root == nullptr) {
            root = CreateNode(x);
            return root;
        }

        //같은 값이 있으면 함수 종료
        if (root->Data == x) {
            cout << "이미 같은 값이 있습니다!" << endl;
            return root;
        }

        //루트를 통해 자식노드를 순회하며 삽입
        if (root->Data < x) { //x값이 data보다 크면 오른쪽 노드로 삽입
            root->Right = Insert(root->Right, x);
        }
        //else if(root->Data > x){ //이미 위에서 ==x값을 검사하기 때문에 else로 해도 됨.
        else {
            root->Left = Insert(root->Left, x);
        }

        return root;
    }
    //삽입 오버로드
    void Insert(char x) { //OverLoad하여 tree의 insert로 전달
        rootNode = Insert(rootNode, x);
    }

    //전위 순회
    void PreOrder(BNode* root) {
        if (root == nullptr) return;  // 종료 조건

        cout << root->Data << endl;//루트노드 출력
        PreOrder(root->Left); //왼쪽자식 이동
        PreOrder(root->Right); //오른쪽자식 이동
    }
    void PreOrder() { //전위 OverLoad
        PreOrder(rootNode);
    }

    //중위 순회
    void InOrder(BNode* root) {
        if (root == nullptr) return;  // 종료 조건

        InOrder(root->Left); //왼쪽자식 이동
        cout << root->Data << endl;//루트노드 출력
        InOrder(root->Right); //오른쪽자식 이동
    }

    void InOrder() {
        InOrder(rootNode);
    }

    //후위 순회
    void PostOrder(BNode* root) {
        if (root == nullptr) return;  // 종료 조건

        PostOrder(root->Left); //왼쪽자식 이동
        PostOrder(root->Right); //오른쪽자식 이동
        cout << root->Data << endl;//루트노드 출력
    }

    void PostOrder() { //후위 오버로드
        PostOrder(rootNode);
    }

    void LevelOrder(BNode* root) {
        Level.push(root); //루트노드를 넣는다.

        //while문으로 큐를 층별로 방문시키며 넣는다.(왼쪽->오른쪽 순)
        while (!Level.empty()) {
            //해당 층의 큐에 노드를 뽑는다.
            root = Level.front();
            Level.pop();

            //값 출력
            cout << root->Data << endl;

            //해당 층의 왼쪽과 오른쪽 노드가 있으면 삽입한다.(다음 층의 출력을 위함)
            if (root->Left != nullptr) {
                Level.push(root->Left);
            }
            if (root->Right != nullptr) {
                Level.push(root->Right);
            }
            
        }
        
    }
    void LevelOrder() {
        LevelOrder(rootNode);
    }
};



int main()
{
    BinaryTree tree;
    //tree.Insert('A');
    //tree.Insert('B');
    //tree.Insert('C');
    //tree.Insert('D');
    //tree.Insert('E');
    //tree.Insert('F');
    //tree.Insert('G');
    //tree.Insert('C'); //이미 있어서 삽입 불가능!
    tree.BuildCustomTree(); //노드 빌드

    tree.PreOrder(); //전위순회 출력
    cout << endl;

    tree.InOrder(); //중위 순회 출력
    cout << endl;

    tree.PostOrder(); //후위 순회 출력
    cout << endl;

    tree.LevelOrder(); //층별 순회 출력

    return 0;
}
