INCLUDE Irvine32.inc
.data
array BYTE 50 DUP(?)
elements dword ?		;number of elements in the array
text1 BYTE "Array: ",0
text2 BYTE "Sorted: "

.code
main PROC
call Randomize			;determine no. of elements in arr
mov eax, 51
call RandomRange
mov DWORD PTR elements, eax
add elements, 10

call fill

mov edx, offset text1	;unsorted display
call WriteString
mov ecx, offset array
call display

mov edi, offset array
mov ecx, elements
call sort

mov edx, offset text2	;sorted display
call WriteString
mov ecx, offset array
call display

exit
main endp

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

fill PROC				;fill the array with random no.
mov eax, 0
mov ecx, elements
mov esi, 0

random:
mov ah, BYTE PTR 1000
call RandomRange
add eax, 1
mov array[esi], ah
inc esi
loop random

ret
fill ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;

display PROC			;display the current array
mov eax, 0
mov ecx, elements
mov esi, 0

displayit:
mov al, array[esi]
call WriteInt
inc esi
loop displayit
call Crlf
ret
display ENDP

;;;;;;;;;;;;;;;;;;;;;;;;

sort PROC				;time to sort em'
dec ecx					;(takes) edi=offset arr, ecx=elements
mov ebx, edi
mov edx, ecx

outer:
mov edi, ebx
mov esi, edi
inc esi
push ecx
mov ecx, edx

inner:
mov al, [esi]
cmp al, [edi]
inc esi
inc edi
jae noSwap
mov al, [esi - 1]		;swap em'
mov ah, [edi - 1]
mov[esi - 1], ah
mov[edi - 1], al

noSwap:
loop inner
pop ecx
loop outer

ret
sort ENDP
END main
