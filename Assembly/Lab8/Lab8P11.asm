INCLUDE Irvine32.inc
.data
K DWORD ?
arr BYTE 50 DUP(0)
.code
main proc


mov K, 2
mov ebx, K
call multiple
call writeint

mov K, 3
mov ebx, K
call multiple
call writeint

exit
main endp




multiple PROC 

mov esi, 0
mov ecx, 50
mov edx, K
LP1:
inc esi
mov al, arr[esi]
sub al, arr
call dumpregs


ret
multiple ENDP
END main


