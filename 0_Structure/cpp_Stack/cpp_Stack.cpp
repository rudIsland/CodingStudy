/*
스택Stack
FILO Frist In Last Out 형태로 동작하며, 가변형태를 가지는 자료구조이다.

원시배열은 크기가 고정되어 있기때문에,
가변 배열인 Single Linked List로 구현하는것이 적합하다.

Why?
스택은 출입구가 하나이므로 Single연결리스트로 push, pop시에 O(1)로 가능하기 때문이다.

*/

#include <iostream>
using namespace std;

struct SNode {
    //데이터
    int Data = 0;
    
    //다음 노드
    SNode* next = nullptr; //다음 노드(위에 아래로 내려가는 노드로 보면 된다.)
};

struct Stack {
    SNode* Head = nullptr; //스택은 가장 위에것만 사용

    // 삽입
    void Push(int x) {
        SNode* newNode = new SNode();
        newNode->Data = x;
        newNode->next = Head;
        Head = newNode;
    }

    //꺼내기
    void Pop() {
        //만약 스택의 헤드가 없으면 리턴. (스택이 비어있단 뜻)
        if (Head == nullptr) return;

        //여기왔다면 값이 있단 뜻
        //스택의 Head를 SNode의 next로 설정하고 기존 Head를 동적할당 해제한다.
        SNode* PopNode = Head;
        Head = PopNode->next;

        delete PopNode;
    }

    void DisplayStack() {

        SNode* node = Head; //스택의 헤드를 가져온다.

        //nullptr이 아닐때까지 반복
        while (node != nullptr) {
            cout << "Stack값: " << node->Data << endl; //값 출력 후
            node = node->next; //노드를 아래로 내린다.
        }
    }

    void Top() {
        cout << "Top값: " << Head->Data << endl;
    }

    bool isEmpty() {
        //헤드가 없으면 비어있단 뜻
        if (Head == nullptr) {
            return true;
        }
        return false;
    }

    //소멸자
    ~Stack() {
        while (!isEmpty()) {
            Pop(); //하나씩 꺼내며 해제
        }
    }

};


int main()
{
    Stack stack;
    stack.Push(3);
    stack.Push(5);
    stack.Push(6);
    stack.Push(2);
    stack.Push(4);

    stack.DisplayStack(); // 4 2 6 5 3
    cout << "-------------" << endl;

    stack.Pop(); //4꺼내기
    stack.Top(); //2값만 출력
    stack.Pop(); //2꺼내기

    stack.DisplayStack();// 6 5 3


    return 0;
}