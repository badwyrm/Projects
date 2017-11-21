TITLE Str_Concat(WA5.asm)

; Program Description : This program concatenates a source string to a target string.
; Author:
; Date Created : 2 / 6 / 2013


INCLUDE Irvine32.inc

.data
source BYTE "Rocks", 0
target BYTE "Zachary", 0
buffer BYTE 24 DUP(0)

.code
main PROC
push ds
pop es

mov esi, OFFSET source
mov edi, OFFSET target
cld; direction = forward
mov eax, LENGTHOF source
rep movsb

call WriteString
call crlf


exit; exit to operating system
main ENDP

END main