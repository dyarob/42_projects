global	_ft_memcpy

section	.text

_ft_memcpy:
cld
mov		rcx, rdx
rep
	movsb
mov		rax, rdi
ret
