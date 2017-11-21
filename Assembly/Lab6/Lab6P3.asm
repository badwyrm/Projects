INCLUDE Irvine32.inc
.data
arr DWORD 3,5,6,9,15
sum DWORD ?

.code
main PROC
mov eax, 0
mov esi, OFFSET arr
mov ecx, LENGTHOF arr - 1

L1:
add eax, [esi + 4]
sub eax, [esi]
add esi, TYPE arr
add sum, eax
loop L1

call WriteInt

exit
main ENDP
END main