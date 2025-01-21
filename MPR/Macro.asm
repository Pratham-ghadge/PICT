

%macro rw 3
mov rax,%1
mov rdi,01
mov rsi,%2
mov rdx,%3
syscall
%endmacro


section .bss
num resb 2

section .text
global _start
_start:

rw 00,num,02

mov al,byte[num]
x:
inc al

y:

rw 01,num,02

mov rax,60
mov rdi,0
syscall
