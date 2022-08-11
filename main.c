
#include <windows.h>
#include <stdio.h>


int main(){
    unsigned char opcodes[5] = { 0x89, 0xC8, 0x01, 0xD0, 0xC3 }; //MOV EAX, ECX; ADD EAX, EDX; RET
    int length = 5;

    int (* sum) (int,int) = NULL;
 

    HANDLE memoryhandle = CreateFileMappingA( INVALID_HANDLE_VALUE, NULL, PAGE_EXECUTE_READWRITE, 0,  length, NULL);

    sum = MapViewOfFile( memoryhandle, FILE_MAP_ALL_ACCESS | FILE_MAP_EXECUTE, 0x0, 0x0, length);

   
    memcpy(sum, opcodes, sizeof(opcodes));
 
   
    int r=sum(10,40);
    printf("result: %d\n", r);

    return 0;
}
//using https://defuse.ca/online-x86-assembler.htm#disassembly for disassembly 