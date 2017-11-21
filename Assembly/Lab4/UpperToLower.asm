INCLUDE Irvine32.inc

.data
string DB 'ABCDE', 0


.code
main 	PROC
mov edx, OFFSET string
call WriteString

mov   al, string
add al, 20h; converts to lowercase letter
mov string, al

mov   al, [string + 1]
add al, 20h; converts to lowercase letter
mov[string + 1], al

mov   al, [string + 2]
add al, 20h; converts to lowercase letter
mov[string + 2], al

mov   al, [string + 3]
add al, 20h; converts to lowercase letter
mov[string + 3], al

mov   al, [string + 4]
add al, 20h; converts to lowercase letter
mov[string + 4], al

mov edx, OFFSET string
call WriteString

exit
main 	ENDP
END	main

