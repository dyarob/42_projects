global _hello

section .text

_hello:
mov     rax, 0x2000004 ; write
mov     rdi, 1 ; stdout
lea     rsi, [rel msg]
mov     rdx, msg.len
syscall

mov     rax, 0x2000001 ; exit
mov     rdi, 0
syscall


section .data

msg:    db      "Hello, world", 10, 0
.len:   equ     $ - msg
