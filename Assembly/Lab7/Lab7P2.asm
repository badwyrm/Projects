INCLUDE Irvine32.inc
.data
index DWORD 1
chars BYTE 'H','A','C','E','B','D','F','G'
links DWORD 0,  4,  5,  6,  2,  3,  7,  0
array BYTE  0,  0,  0,  0,  0,  0,  0,  0

.code
main PROC
mov ecx, 8
mov edi, 1

mov al, chars[1]
mov array, al
mov esi, index
mov ebx, offset links


L1:
mov eax, links[esi * 4]
mov dl, chars[eax]
mov array[edi], dl
mov esi,eax
inc edi
loop L1


mov ecx,8
mov esi,0
L2:
mov al, array[esi]
inc esi
call WriteChar
loop L2

exit
main ENDP
END main
