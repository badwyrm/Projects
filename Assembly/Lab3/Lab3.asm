INCLUDE Irvine32.inc
.data
array BYTE 10,20,30,40
convert DWORD ?
.code
main PROC
mov eax DWORD PTR array
mov convert,eax
call WriteHex
call ReadInt
exit
main ENDP
END main