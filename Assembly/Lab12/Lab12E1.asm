INCLUDE Irvine32.inc
.data
key BYTE -6, 4, 2, 0, -7, 3, -1, 5, -4, 8
array BYTE "AndrewTranLab12", 0

.code
main PROC
mov eax, OFFSET array
mov edi, OFFSET key
mov ecx, 20
mov edx, OFFSET array
call WriteString
call Crlf
call Encrypt
mov edx, OFFSET array
call WriteString
call Crlf

exit
main ENDP

Encrypt Proc
encryption:
push ecx
mov cl, [edi]
cmp cl, 0
jge right
rol BYTE PTR[eax], cl		;left
jmp incre
right:
ror BYTE PTR[eax], cl		;right
incre:
inc eax
inc edi
pop ecx
loop encryption
ret
Encrypt ENDP

END main