INCLUDE Irvine32.inc

.data

.code
main PROC




ShowParams proc
mov edx, OFFSET stackparam
call WriteString
mov ecx, 8
L2:
mov edx, OFFSET address
call WriteString
mov eax, ebp
add eax, 4
call WriteHex
mov edx, OFFSET equals
call WriteString
mov eax, ebp
add eax, 8
call WriteHex
add ebp, 4
mov edx, OFFSET endl
call WriteString
loop L2
ret

ShowParams endp
exit
main ENDP
END main
