INCLUDE Irvine32.inc

Str_concat PROTO, source:PTR BYTE, target : PTR BYTE
.data
targetStr BYTE "ABCDE", 10 DUP(0)
sourceStr BYTE "FGH", 0
.code
main PROC
mov edx, OFFSET targetStr
call WriteString
call Crlf
call WaitMsg
mov eax, LENGTHOF sourceStr
INVOKE Str_concat, ADDR sourceStr, ADDR targetStr
mov edx, OFFSET targetStr
call WriteString
call Crlf
exit
main ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

Str_concat PROC USES eax ecx esi edi, source:PTR BYTE, target : PTR BYTE
mov ecx, eax					; LENGTHOF source
mov esi, source
mov edi, target
add edi, 5
cld								; forward
rep movsb						; copy
ret
Str_concat ENDP
END main