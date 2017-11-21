INCLUDE Irvine32.inc
Str_find PROTO, sourcePtr:PTR BYTE, targetPtr:PTR BYTE

.data
source BYTE "Andrew Tran Lab 12", 0
target BYTE "rew", 0
lengthA DWORD ?
response BYTE "Target was found."

.code
main PROC
mov edx, OFFSET source
call WriteString
call crlf
mov ecx, (SIZEOF target)
mov edx, OFFSET target
call WriteString
call crlf
INVOKE Str_find, ADDR source,ADDR target
jz quit
Found:
mov edx, OFFSET response
call WriteString
call crlf
quit:
main ENDP
exit

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

Str_find PROC, sourcePtr:PTR BYTE, targetPtr : PTR BYTE
mov eax, sourcePtr
mov ebx, targetPtr
mov esi, targetPtr					;beginning of the string
xor ecx, ecx						;ecx = 0
L0:
cmp BYTE PTR[esi], 0
je L1								;true		
inc esi
inc ecx
jmp L0; FALSE:Jump to L0			;false
L1 :
mov edx, ecx
L2:
mov esi, eax					;cmpsb setup
mov edi, ebx					;cmpsb setup
repe cmpsb
jz Found
mov ecx, edx
cmp BYTE PTR[eax + ecx], 0
jz Not_Found
inc eax
jmp L2
Not_Found:
or eax, 1						;reset zero flag
ret								;return failure
Found:
mov eax, ebx
call dumpregs					;show eax contents
mov lengthA, edx
sub esi, lengthA
ret
Str_find ENDP
END main