section .data
section .bss
num resb 2

section .text
global _start
_start:
; Read Syscall
mov rax,0
mov rdi,0
mov rsi,num
mov rdx,2
syscall

mov al,byte[num]
x:           ; set 1st breakpoint for the debugger
inc al

;Write Syscall

y:           ; Set 2nd breakpoint for the debugger
mov rax,1
mov rdi,1
mov rsi,num
mov rdx,2
syscall

;Exit Syscall
mov rax,60
mov rdi,0
syscall
