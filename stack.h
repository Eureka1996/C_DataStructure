#pragma once
#ifndef _MY_STACK_H_
#define _MY_STACK_H_

typedef void Stack;

Stack* Stack_Create();

void Stack_Destroy(Stack* stack);

void Stack_Clear(Stack* stack);

int Stack_Push(Stack* stack, void* item);

void* Stack_Pop(Stack* stack);

void* Stack_Top(Stack* stack);

int Stack_Size(Stack* stack);

#endif