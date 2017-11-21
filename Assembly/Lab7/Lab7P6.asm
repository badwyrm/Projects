INCLUDE Irvine32.inc

.data
String BYTE 10 DUP(0), 0

.code
main PROC
mov ecx, 20

L1: 
push ecx
mov ecx, 10
mov esi, OFFSET String


L2:
mov eax, 26
call RandomRange
add eax, 'A'
mov[esi], al
inc esi
loop L2


mov edx, OFFSET String
call WriteString
call Crlf
pop ecx
loop L1

exit
main ENDP
END main
