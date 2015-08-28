global	_ft_isprint

section	.text

_ft_isprint:
cmp	rdi, 0x20
jl	end
cmp	rdi, 0x7e
jg	end
mov rax, 1
ret

end:
mov	rax, 0
ret
