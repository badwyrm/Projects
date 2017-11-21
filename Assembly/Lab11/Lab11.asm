INCLUDE Irvine32.inc

DECIMAL_OFFSET = 5
.data
array BYTE "100123456789765"
data BYTE(SIZEOF array + 1) DUP(? )
.code
main PROC
mov edx, OFFSET array;		pass in offset in edx
mov ecx, 15;				pass in number length in ecx
mov ebx, DECIMAL_OFFSET;	pass in decimal offset in ebx

mov edx, OFFSET array
call WriteString
call crlf
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

call WriteScaled

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
mov edx, OFFSET data
call WriteString
call crlf
main ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


WriteScaled PROC
sub ecx, ebx
mov esi,0
L1:
mov ah, array[esi];			loop in array into data
mov data[esi], ah
inc esi
loop L1
mov data[esi], '.';			add in period
inc esi
mov ecx,5					set to decimal offset


L2:
mov ah, array[esi - 1];		put in the rest of array
mov data[esi], ah
inc esi
loop L2
ret
WriteScaled ENDP
END main


