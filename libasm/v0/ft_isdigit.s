global	_ft_isdigit

section	.text

_ft_isdigit:
cmp	rdi, 0x30	;0
jl	end
cmp	rdi, 0x39	;9
jg	end
mov	rax, 1
ret

end:
mov	rax, 0
ret
