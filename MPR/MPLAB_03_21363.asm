%macro rw 3
mov rax,%1
mov rdi,%1
mov rsi,%2
mov rdx,%3
syscall
%endmacro rw

section .data
arr db 09h,02h,-07h,-0ah,
count db 5

pcount db "0"
ncount db "0"

;msg1 db "Enter a string",10
;len1 equ $-msg1

stt1 dq "To check the number of positive and negative numbers",10
l1 equ $-stt1

section .bss
;ncount resb 1
;pcount resb 1
p resb 1
n resb 1


global _start
section .text
_start:
	rw 1,stt1,l1

;ASSIGN COUNTER TO ZERO
	mov byte[ncount],0h
	mov byte[pcount],0h

;SET POINTER TO POINT arr	
	mov rbp,arr

loop:	
	mov rax,[rbp]
	rcl rax,1
	jc neg
	inc byte[pcount]
	jmp next
	
neg: 
	inc byte[ncount]	

next: 
	inc rbp
	dec byte[count]
	jnz loop

;mov al,byte[pcount]
rw 1, pcount,1
;mov rax,01
;mov rdi,01
;mov rsi,[al]
;mov rdx,1
;syscall


exit:	mov rax,60
	mov rdi,0
	syscall
