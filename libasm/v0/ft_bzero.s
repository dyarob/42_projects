global	_ft_bzero

section	.text

_ft_bzero:
cmp	rsi, 0
je	end
mov	BYTE[rdi], 0
sub	rsi, 1
add	rdi, 1
jmp	_ft_bzero

end:
ret
