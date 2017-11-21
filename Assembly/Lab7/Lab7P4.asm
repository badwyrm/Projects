INCLUDE Irvine32.inc

.data
string BYTE "Enter an integer: ",0
string1 BYTE "The sum is: ",0
sum DWORD 0
row BYTE 9
col BYTE 25

.code
main 	PROC
mov ecx, 2
mov ebx, 3
mov sum, 0

L2:
call Clrscr

L1:
dec ebx
mov dh, row
mov dl, col
call GoToXY
mov edx, OFFSET string
call WriteString
call ReadInt
add sum, eax
add row,2

mov dh, row
mov dl, col
call GoToXY
mov edx, OFFSET string1
call WriteString
mov eax, sum
call WriteInt
loop L1

mov ecx, ebx
loop L2


exit
main ENDP
END main
