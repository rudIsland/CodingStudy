/*
양방향 연결리스트 구현(Linked List)

연결리스트는 (헤드포인터 , 값, 꼬리포인터)로 구성되어 있다.

*/
#include <iostream>
using namespace std;

//리스트의 노드
struct LinkedNode {
    int Data=0;
    //항상 nullptr로 초기화
    LinkedNode* prev = nullptr; //헤드 노드
    LinkedNode* next = nullptr; //꼬리 노드
};

// 리스트 전체 구조
struct LinkedList {
    LinkedNode* head = nullptr;
    LinkedNode* tail = nullptr;
};

//삽입
void InsertNode(LinkedList* list, int value) {
    LinkedNode* newNode = new LinkedNode(); //새로 삽입할 노드에 구조체 할당
    newNode->Data = value; //값을 넣어준다.

    if (list->head == nullptr) {  //헤드가 nullptr이면 삽입
        list->head = list->tail = newNode;
    }
    else { //헤드가 있으면 리스트의 꼬리의 다음으로 삽입
        list->tail->next = newNode;
        newNode->prev = list->tail; //새노드의 이전값은 리스트의 꼬리로 설정
        list->tail = newNode; //리스트의 꼬리에도 설정
    }
}

bool DeleteNode(LinkedList* list, LinkedNode* delNode) {

    if (delNode->prev) //삭제할 노드의 이전노드가 있을경우
        delNode->prev->next = delNode->next; //삭제노드의 이전노드의다음을 삭제할노드의 다음노드로 연결
    else
        list->head = delNode->next; // 첫 노드였다면 head 갱신

    // 다음 노드가 있으면 연결
    if (delNode->next)
        delNode->next->prev = delNode->prev;
    else
        list->tail = delNode->prev; // 마지막 노드였다면 tail 갱신

    delete delNode;
    return true;

}

//노드 보여주기
void ShowList(LinkedList* list) {
    LinkedNode* showNode = list->head; //리스트의 헤드를 가져온다.
    while (showNode != nullptr) { //해당 노드가 차례로 nullptr이 아니면 출력하고
        cout << showNode->Data << "\t";
        showNode = showNode->next; //다음으로 이동하여 순회
    }
    cout << endl;
}

// 찾기
LinkedNode* FindNode(LinkedList* list, int value) {
    LinkedNode* curr = list->head; //리스트의 현재 노드를 하나씩 가져와서 순회
    while (curr) {
        if (curr->Data == value) return curr; //같은 값이 있으면 반환
        curr = curr->next; //다음으로 이동
    }
    return nullptr;
}

int main()
{
    //지역변수 LinkedList 구조체 정의
    LinkedList Linkedlist;

    InsertNode(&Linkedlist, 2);
    InsertNode(&Linkedlist, 5);
    InsertNode(&Linkedlist, 9);
    InsertNode(&Linkedlist, 4);

    cout << "-----전체 출력-----" << endl;
    ShowList(&Linkedlist);

    cout << endl << "-----삭제 후------" << endl;
    LinkedNode* fNode = FindNode(&Linkedlist, 9); //원소가 9인 값을 찾아 해당 노드를 반환, 값이 없으면 nullptr
    DeleteNode(&Linkedlist, fNode);
    ShowList(&Linkedlist); //삭제 후 리스트 출력

    return 0;
}

