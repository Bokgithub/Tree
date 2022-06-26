/*

I affirm that I did not give or receive any
unauthorized help on this assignment.
ALL WORK IS ON MY OWN.

Name: 조보경
SID: 2021189038

*/

#include "module.h"



node* makeTreeBFS(char* line) {
    // TODO: Make a tree with the given line, which is written as BFS behavior.
    // return: root node

    char* temp = line; 
    queue* q = q_init();
    node* root = makeNode(atoi(line)); //line에서 첫번째 숫자로 root node 만듦.
    node* last= root; //last로 parent node를 지정.
    q_enqueue(q ,root); 
    int i = 0;

    while ((( * temp) != ' ') && (( * temp) != '|'))
    {
        i++;
        temp = line + i; //temp 포인터로 line에 있는 char를 하나씩 포인트함.
    }

    while(true)
    {
        if (*temp == '\0') { //temp가 마지막 문자열을 가르킬 때 root 반환
            return root;
        }
         
        else if (*temp == '|') //temp가 |가 될 때마다 dequeue한 노드를 parent 노드로 설정
        {
            last = q_dequeue(q);
            i++;
        }

        else if (*temp == ' ') //공백일 때는 아무런 액션 없이 넘어감.
        {
            i++;
        }
        else //line[i]가 int인 경우
        {
            int num = atoi(temp); //atoi함수로 숫자로 변환
            if (last->left == NULL) //left node가 비어있으면 left에 node 추가
            {
                last->left = makeNode(num);
                q_enqueue(q, last->left);
            }
            else //left node가 차있으면 right에 노드 추가
            {
                //int num = *line;
                last->right = makeNode(num);
                q_enqueue(q, last->right);
            }
            while (*temp != ' ' && *temp != '|' && *temp != '\0') //temp는 1씩 증가하는 것이 아니라, 숫자 자리수만큼 이동해야함.
            {
                i++;
                temp = line + i;
            }
        }
        temp = line + i;
    }
    return root;
}

void printBFS(node* root) {
    // TODO: Print the value of node in BFS behavior.
    node* parent = root;
    queue* Q=q_init();
    q_enqueue(Q, root);
    while (q_is_empty(Q)==false) //큐가 비면 출력 멈춤
    {
        parent = q_dequeue(Q);
        if (parent == NULL) //parent가 null일 때는 다음 동작으로 넘어감. 즉, NULL값일 때는 enqueue하지 않음
            continue;
        q_enqueue(Q,parent->left); //자식 노드를 enqueue하고
        q_enqueue(Q,parent->right);
        printf("%d ", parent->val); //parent node를 출력함.
    }
    /////
}

void printPreOrder(node* root) {
    // TODO: Print the value of node in pre-order behavior. <root><left><right>
    node* temp = root;
    if (temp == NULL)
        return 0;
    printf("%d ", temp->val); //root 출력후, left와 right를 출력함
    printPreOrder(temp->left);
    printPreOrder(temp->right);
    /////
}

void printInOrder(node* root) {
    // TODO: Print the value of node in In-order behavior. <left><root><right>
    node* temp = root;
    if (temp == NULL)
        return 0;
    
    printInOrder(temp->left); //left, root, right 순으로 출력
    printf("%d ", temp->val);
    printInOrder(temp->right);

    /////
}

void printPostOrder(node* root) {
    // TODO: Print the value of node in Post-order behavior. <left><right><root>
    node* temp = root;
    if (temp == NULL)
        return 0;

    printPostOrder(temp->left); //left right root 순으로 출력
    printPostOrder(temp->right);
    printf("%d ", temp->val);

    /////
}

void freeTree(node* root) {
    // TODO: Free all nodes in the tree
    node* temp = root;
    if (temp == NULL)
        return 0;

    freeTree(temp->left); //root를 마지막에 free하기 위해, postorder방식으로 탐색하며 free함.
    freeTree(temp->right);
    free(temp);

    /////
}


// Add your functions //

queue* q_init() {
    queue* make = (queue*)malloc(sizeof(queue)); //새로운 queue 생성
    make->front = 0;
    make->rear = 0;
    return make;
}

void q_enqueue(queue* q, node* val) {
    if (q_is_full(q))
    {
        printf("enqueu not allowed\n"); //q가 모두 찼을 때 예외 처리
        return NULL;
    }
    q->element[q->rear] = val; //q의 element배열의 마지막 순서(rear가 가리키는 방)에 val라는 값을 할당
    q->rear = q->rear + 1; //rear는 방이 들어있는 마지막 방의 다음 방(빈 array) 순서 가짐
}

node* q_dequeue(queue* q) {
    node* deq;
    if (q_is_empty(q))
    {
        printf("dequeu not allowed\n"); //q가 비었을 때 예외 처리
        deq = NULL;
    }
    else
    {
        deq = q->element[q->front]; //지우고자 하는 자료(큐의 front가 가리키는 element)를 deq라는 변수에 할당
        q->front = q->front + 1; //큐의 front가 다음 방을 순서 가짐

        return deq;
    }
}

bool q_is_empty(queue* q) {
    bool empt = false;
    if ((q->front) == (q->rear)) // Element에 자료가 하나도 없으면 rear와 front가 가리키는 값 동일
        empt = true;
    return empt;
}

bool q_is_full(queue* q) {
    //q가 모두 차있으면 rear의 값= max_data
    if (q->rear == MAX_DATA)
        return true;
    return false;
}


void push(bucket* q, int tok) {
    // TODO: Push the token in the linked stack

    node* make = malloc(sizeof(node)); //make라는 노드를 만들어서 tok할당 next 초기화
    make->tok = tok;
    make->next = NULL;
    if (q->len == 0)
    {
        q->head = make;
    }
    else
    {
        make->next = q->head; //make의 next를 원래의 첫번째 노드로 할당하고
        q->head = make;  //첫번째 노드를 make로 설정한다.
        q->len += 1; //q len를 하나 증가시킴.
    }
}

char pop(bucket* q) {
    // TODO: Pop the token in the linked queue
    // Return: token char

    if (q->len == 0)
    {
        printf("stack is empty");
        return -1;
    }
    int deq = q->head->tok;
    q->head = q->head->next;
    q->len -= 1;
    return deq;

}


node* makeNode(int val) //val 값으로 node를 만드는 함수
{
    node* new = (node*)malloc(sizeof(node));
    new->val = val;
    new->left = NULL;
    new->right = NULL;

}

bucket* init()
{
    bucket* make = (bucket*)malloc(sizeof(bucket)); //새로운 queue 생성
    make->head = 0;
    make->tail = 0;
    int len = 0;
    return make;
}

/////////////////////////

