INCLUDE Irvine32.inc
.data
prev DWORD ?
next DWORD ?
value DWORD ?
count DWORD ?
total DWORD ?

.code
main PROC
mov	ecx, 47
mov	value, 1
mov	prev, -1
mov	eax, 1
call fibonacci
main ENDP



fibonacci PROC
L1:
mov	count, ecx
mov	ebx, value
add	ebx, prev
mov	total, ebx
mov	ebx, value
mov	prev, ebx
mov	eax, total
mov	value, eax
call WriteInt
loop L1

fibonacci ENDP
END main



