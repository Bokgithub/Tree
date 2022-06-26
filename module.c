/*

I affirm that I did not give or receive any
unauthorized help on this assignment.
ALL WORK IS ON MY OWN.

Name: ������
SID: 2021189038

*/

#include "module.h"



node* makeTreeBFS(char* line) {
    // TODO: Make a tree with the given line, which is written as BFS behavior.
    // return: root node

    char* temp = line; 
    queue* q = q_init();
    node* root = makeNode(atoi(line)); //line���� ù��° ���ڷ� root node ����.
    node* last= root; //last�� parent node�� ����.
    q_enqueue(q ,root); 
    int i = 0;

    while ((( * temp) != ' ') && (( * temp) != '|'))
    {
        i++;
        temp = line + i; //temp �����ͷ� line�� �ִ� char�� �ϳ��� ����Ʈ��.
    }

    while(true)
    {
        if (*temp == '\0') { //temp�� ������ ���ڿ��� ����ų �� root ��ȯ
            return root;
        }
         
        else if (*temp == '|') //temp�� |�� �� ������ dequeue�� ��带 parent ���� ����
        {
            last = q_dequeue(q);
            i++;
        }

        else if (*temp == ' ') //������ ���� �ƹ��� �׼� ���� �Ѿ.
        {
            i++;
        }
        else //line[i]�� int�� ���
        {
            int num = atoi(temp); //atoi�Լ��� ���ڷ� ��ȯ
            if (last->left == NULL) //left node�� ��������� left�� node �߰�
            {
                last->left = makeNode(num);
                q_enqueue(q, last->left);
            }
            else //left node�� �������� right�� ��� �߰�
            {
                //int num = *line;
                last->right = makeNode(num);
                q_enqueue(q, last->right);
            }
            while (*temp != ' ' && *temp != '|' && *temp != '\0') //temp�� 1�� �����ϴ� ���� �ƴ϶�, ���� �ڸ�����ŭ �̵��ؾ���.
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
    while (q_is_empty(Q)==false) //ť�� ��� ��� ����
    {
        parent = q_dequeue(Q);
        if (parent == NULL) //parent�� null�� ���� ���� �������� �Ѿ. ��, NULL���� ���� enqueue���� ����
            continue;
        q_enqueue(Q,parent->left); //�ڽ� ��带 enqueue�ϰ�
        q_enqueue(Q,parent->right);
        printf("%d ", parent->val); //parent node�� �����.
    }
    /////
}

void printPreOrder(node* root) {
    // TODO: Print the value of node in pre-order behavior. <root><left><right>
    node* temp = root;
    if (temp == NULL)
        return 0;
    printf("%d ", temp->val); //root �����, left�� right�� �����
    printPreOrder(temp->left);
    printPreOrder(temp->right);
    /////
}

void printInOrder(node* root) {
    // TODO: Print the value of node in In-order behavior. <left><root><right>
    node* temp = root;
    if (temp == NULL)
        return 0;
    
    printInOrder(temp->left); //left, root, right ������ ���
    printf("%d ", temp->val);
    printInOrder(temp->right);

    /////
}

void printPostOrder(node* root) {
    // TODO: Print the value of node in Post-order behavior. <left><right><root>
    node* temp = root;
    if (temp == NULL)
        return 0;

    printPostOrder(temp->left); //left right root ������ ���
    printPostOrder(temp->right);
    printf("%d ", temp->val);

    /////
}

void freeTree(node* root) {
    // TODO: Free all nodes in the tree
    node* temp = root;
    if (temp == NULL)
        return 0;

    freeTree(temp->left); //root�� �������� free�ϱ� ����, postorder������� Ž���ϸ� free��.
    freeTree(temp->right);
    free(temp);

    /////
}


// Add your functions //

queue* q_init() {
    queue* make = (queue*)malloc(sizeof(queue)); //���ο� queue ����
    make->front = 0;
    make->rear = 0;
    return make;
}

void q_enqueue(queue* q, node* val) {
    if (q_is_full(q))
    {
        printf("enqueu not allowed\n"); //q�� ��� á�� �� ���� ó��
        return NULL;
    }
    q->element[q->rear] = val; //q�� element�迭�� ������ ����(rear�� ����Ű�� ��)�� val��� ���� �Ҵ�
    q->rear = q->rear + 1; //rear�� ���� ����ִ� ������ ���� ���� ��(�� array) ���� ����
}

node* q_dequeue(queue* q) {
    node* deq;
    if (q_is_empty(q))
    {
        printf("dequeu not allowed\n"); //q�� ����� �� ���� ó��
        deq = NULL;
    }
    else
    {
        deq = q->element[q->front]; //������� �ϴ� �ڷ�(ť�� front�� ����Ű�� element)�� deq��� ������ �Ҵ�
        q->front = q->front + 1; //ť�� front�� ���� ���� ���� ����

        return deq;
    }
}

bool q_is_empty(queue* q) {
    bool empt = false;
    if ((q->front) == (q->rear)) // Element�� �ڷᰡ �ϳ��� ������ rear�� front�� ����Ű�� �� ����
        empt = true;
    return empt;
}

bool q_is_full(queue* q) {
    //q�� ��� �������� rear�� ��= max_data
    if (q->rear == MAX_DATA)
        return true;
    return false;
}


void push(bucket* q, int tok) {
    // TODO: Push the token in the linked stack

    node* make = malloc(sizeof(node)); //make��� ��带 ���� tok�Ҵ� next �ʱ�ȭ
    make->tok = tok;
    make->next = NULL;
    if (q->len == 0)
    {
        q->head = make;
    }
    else
    {
        make->next = q->head; //make�� next�� ������ ù��° ���� �Ҵ��ϰ�
        q->head = make;  //ù��° ��带 make�� �����Ѵ�.
        q->len += 1; //q len�� �ϳ� ������Ŵ.
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


node* makeNode(int val) //val ������ node�� ����� �Լ�
{
    node* new = (node*)malloc(sizeof(node));
    new->val = val;
    new->left = NULL;
    new->right = NULL;

}

bucket* init()
{
    bucket* make = (bucket*)malloc(sizeof(bucket)); //���ο� queue ����
    make->head = 0;
    make->tail = 0;
    int len = 0;
    return make;
}

/////////////////////////

