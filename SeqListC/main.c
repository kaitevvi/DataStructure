#include"SeqList.h"

int main() {
    SeqList seqList;
    SeqListInit(&seqList);
//    SeqListPushBack(&seqList, 1);
//    SeqListPushBack(&seqList, 2);
//    SeqListPushBack(&seqList, 3);
//    SeqListPushBack(&seqList, 4);
//    SeqListPushBack(&seqList, 5);
    SeqListPrint(&seqList);
    SeqListDestroy(&seqList);
    return 0;
}
