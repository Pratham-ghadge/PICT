

%macro rw 3
mov rax,%1
mov rdi,01
mov rsi,%2
mov rdx,%3
syscall
%endmacro

section .data
m1 db "Enter Two Numbers :",10
l1 equ $-m1
m2 db "Display :",10
l2 equ $-m2
count db 02h

section .bss
num resb 34


section .text
global _start
_start:


rw 01,m1,l1
mov rbx,num

x:
rw 00,rbx,17
add rbx,17
dec byte[count]
jnz x

rw 01,m2,l2
mov rbx,num

y:
rw 01,rbx,17
add rbx,17
dec byte[count]
jnz y


mov rax,60
mov rdi,0
syscall
