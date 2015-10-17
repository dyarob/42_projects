global	_ft_strdup
extern	_malloc, _ft_strlen

section	.text

_ft_strdup:
push	rdi
call	_ft_strlen
add		rax, 1
push	rax
mov		rdi, rax
call	_malloc
cmp		rax, 0
je		end

mov		rdi, rax
pop		rcx
pop		rsi
push	rdi
rep		movsb
pop		rax

end:
ret
