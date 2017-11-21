INCLUDE Irvine32.inc
.data
arr BYTE 43h,69h,11h,97h
convert DWORD ?
.code
main PROC
mov eax,DWORD PTR arr
mov convert,eax
call WriteHex

exit
main ENDP
END main
