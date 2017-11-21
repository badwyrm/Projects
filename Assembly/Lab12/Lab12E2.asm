INCLUDE Irvine32.inc

.data
input BYTE "Enter an integer: ", 0
ansGCD BYTE "GCD: ", 0
val1 DWORD ?
val2 DWORD ?
.code
main PROC
mov edx, OFFSET input
call WriteString
call ReadDec
mov val1, eax
mov edx, OFFSET input
call WriteString
call ReadDec
mov val2, eax
mov eax, DWORD ptr[val1]
mov ebx, DWORD ptr[val2]
push val2
push val1
call gcd
exit
main ENDP

gcd PROC
xor edx, edx
mov eax, DWORD ptr[esp + 8]
mov ebx, DWORD ptr[esp + 4]
hi:
div ebx; eax / ebx
cmp edx, 0
je L1
mov eax, ebx
mov ebx, edx
jmp hi

L1:
mov eax, ebx
mov edx, OFFSET ansGCD
call WriteString
call WriteDec
call Crlf
ret 8
gcd ENDP

END main