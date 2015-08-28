global	_ft_puts
extern	_write, _ft_strlen

section	.text

_ft_puts:
push	rdi		; save rdi cuz strlen will modify it
call	_ft_strlen
mov		rdx, rax
pop		rsi		; pop original value of rdi into rsi (2nd argument to write)
mov		rdi, 1	; stdout
call	_write
ret
