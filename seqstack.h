#pragma once


#ifndef _MY_SEQLIST_H__
#define _MY_SEQLIST_H__

typedef void SeqStack;
typedef void SeqStackNode;

SeqStack* SeqStack_Create(int capacity);

void SeqStack_Destroy(SeqStack* stack);

void SeqStack_Clear(SeqStack* stack);

int SeqStack_Push(SeqStack* stack, SeqStackNode* node);

SeqStackNode* SeqStack_Pop(SeqStack* stack);

int SeqStack_Size(SeqStack* stack);

int SeqStack_Capacity(SeqStack* stack);

SeqStackNode* SeqStack_Top(SeqStack* stack);



#endif