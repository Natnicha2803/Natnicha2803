#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    struct Node *Next;
    struct Node *Back;
} typedef N;

void AddNode(N **, int Data);
void InsertNode(N **, int Data, int pos);
void DeleteNode(N **, int pos);
void SwapNode(N **, int pos1, int pos2);
void ShowFront(N *);
void ShowBack(N *);

int main() {
    N *start = NULL;
    int data = 0, pos1 = 0, pos2 = 0;

    printf("Add (data) : "); 
    scanf("%d", &data); AddNode(&start, data);
    printf("Add (data) : "); 
    scanf("%d", &data); AddNode(&start, data);
    printf("Add (data) : "); 
    scanf("%d", &data); AddNode(&start, data);
    ShowFront(start);
    ShowBack(start);

    printf("Insert (data pos) : "); 
    scanf("%d %d", &data, &pos1); InsertNode(&start, data, pos1);
    printf("Insert (data pos) : "); 
    scanf("%d %d", &data, &pos1); InsertNode(&start, data, pos1);
    printf("Insert (data pos) : "); 
    scanf("%d %d", &data, &pos1); InsertNode(&start, data, pos1);
    ShowFront(start);

    printf("Delete (pos) : "); 
    scanf("%d", &pos1); DeleteNode(&start, pos1);
    printf("Delete (pos) : "); 
    scanf("%d", &pos1); DeleteNode(&start, pos1);
    ShowFront(start);

    printf("Swap (pos1 pos2) : "); 
    scanf("%d %d", &pos1, &pos2);
    SwapNode(&start, pos1, pos2);
    ShowFront(start);
    return 0;
}

void AddNode(N **Walk, int Data) {
    N *newNode = (N *)malloc(sizeof(N));
    newNode->Data = Data;
    newNode->Next = NULL;
    newNode->Back = NULL;

    if (*Walk == NULL) {
        *Walk = newNode;
    } else {
        N *temp = *Walk;
        while (temp->Next) {
            temp = temp->Next;
        }
        temp->Next = newNode;
        newNode->Back = temp;
    }
}

void ShowFront(N *Walk) {
    
    printf("Show Front : ");
    while (Walk) {
        printf("%d ", Walk->Data);
        Walk = Walk->Next;
    }
    printf("\n");
    
}

void ShowBack(N *Walk) {
    
    N *temp = Walk;
    while (temp->Next) {
        temp = temp->Next;
    }

    printf("Show Back : ");
    while (temp) {
        printf("%d ", temp->Data);
        temp = temp->Back;
    }
    printf("\n");
}

void InsertNode(N **Walk, int Data, int position) {
    N *newNode = (N *)malloc(sizeof(N));
    newNode->Data = Data;
    newNode->Next = NULL;
    newNode->Back = NULL;

    if (position == 1) {
        newNode->Next = *Walk;
        if (*Walk) (*Walk)->Back = newNode;
        *Walk = newNode;
        return;
    }

    N *temp = *Walk;
    for (int i = 1; temp && i < position - 1; i++) {
        temp = temp->Next;
    }

    if (!temp) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->Next = temp->Next;
    if (temp->Next) {
        temp->Next->Back = newNode;
    }
    temp->Next = newNode;
    newNode->Back = temp;
}

void DeleteNode(N **Walk, int position) {
    if (*Walk == NULL) {
        printf("List is empty\n");
        return;
    }

    N *temp = *Walk;

    if (position == 1) {
        *Walk = temp->Next;
        if (*Walk) (*Walk)->Back = NULL;
        free(temp);
        return;
    }

    for (int i = 1; temp && i < position; i++) {
        temp = temp->Next;
    }

    if (!temp) {
        printf("Position out of range\n");
        return;
    }

    if (temp->Next) {
        temp->Next->Back = temp->Back;
    }
    if (temp->Back) {
        temp->Back->Next = temp->Next;
    }
    free(temp);
}

void SwapNode(N **Walk, int pos1, int pos2) {
    if (pos1 == pos2) return;

    N *temp1 = *Walk, *temp2 = *Walk;
    int i;

    for (i = 1; temp1 && i < pos1; i++) {
    temp1 = temp1->Next;
    }
    for (i = 1; temp2 && i < pos2; i++) {
    temp2 = temp2->Next;
    }
   
    int tempData = temp1->Data;
    temp1->Data = temp2->Data;
    temp2->Data = tempData;
}



