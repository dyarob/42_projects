section .data
msg db 'This is a test', 10, 0    ; something stupid here

section .text
global _main2
extern _printf

_main2:
push    rbp
mov     rbp, rsp       

xor     al, al
lea     rdi, [rel msg]
call    _printf

mov     rsp, rbp
pop     rbp
ret
