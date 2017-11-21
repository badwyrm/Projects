INCLUDE Irvine32.inc
.data
arr DWORD 1,2,3,4
.code
main PROC
mov esi,0
mov ecx,2

L1:
mov eax, arr[esi]
mov ebx, arr[esi + 4]
mov arr[esi], ebx
mov arr[esi + 4], eax

add esi, 8
loop L1

mov esi, 0
mov ecx, 4

L2:
mov eax, arr[esi]
call WriteInt
add esi, 4
loop L2


exit
main ENDP
END main