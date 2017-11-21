INCLUDE Irvine32.inc

.data
string DB 'abcde', 0

.code
main 	PROC
mov edx, OFFSET string
call WriteString

mov   al, string
and al, 0DFh; converts to uppercase letter
mov string, al

mov   al, [string + 1]
and al, 0DFh; converts to uppercase letter
mov[string + 1], al

mov   al, [string + 2]
and al, 0DFh; converts to uppercase letter
mov[string + 2], al

mov   al, [string + 3]
and al, 0DFh; converts to uppercase letter
mov[string + 3], al

mov   al, [string + 4]
and al, 0DFh; converts to uppercase letter
mov[string + 4], al

mov edx, OFFSET string
call WriteString

exit
main 	ENDP
END	main
