INCLUDE Irvine32.inc

.data

.code
main PROC
; carry flag
mov al, 3
sub al, 4; the most significiant bit went out of range
call dumpregs

; zero flag
mov eax, 3
sub eax, 3; makes a zero value in eax
call dumpregs

; sign flag
mov al, 10
sub al, 11; makes a negative eax value
call dumpregs

; overflow flag
mov al, 10000000b
add al, 11111110b; two negative values make a postive
call dumpregs

exit
main ENDP
END main
