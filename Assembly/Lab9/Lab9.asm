INCLUDE Irvine32.inc
.data
msg BYTE "String: ", 0
msg2 BYTE "Character: ", 0
string BYTE 51 DUP(0)
char BYTE ?
count DWORD ?

.code
main PROC
mov edx, OFFSET msg
call writeString
mov edx, OFFSET string
mov ecx, 50
call readString
mov count, eax
call crlf
mov edx, OFFSET msg2
call writeString


call readChar
mov char, al
call crlf
call crlf
mov ecx, count
mov edx, OFFSET string


call removal
mov edx, OFFSET string
call writeString
call crlf
main ENDP





removal PROC
mov eax, 0;			keep a count of string w/o chosen char
L1:
movzx edx,string[ecx]
cmp dl, char;		compare it to the letter
jz match;			jump if match
push edx;			otherwise push the non - chosen char onto stack
inc eax;			inc the count w/o chosen char

match:
mov string[ecx], 0;	replace with 0 if match
loop L1
mov ecx, eax;		move count to ecx
mov eax, 0

L3:
pop edx;			pop back all non - chosen char back
mov BYTE PTR string[eax], dl
inc eax			
loop L3
ret
removal ENDP

END main
