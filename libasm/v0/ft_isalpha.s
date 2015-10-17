global	_ft_isalpha

section	.text

_ft_isalpha:
cmp	rdi, 0x5a	;Z
jg	min
cmp	rdi, 0x41	;A
jl	end
mov	rax, 1
ret

min:
cmp	rdi, 0x61	;a
jl	end
cmp	rdi, 0x7a	;z
jg	end
mov	rax, 1
ret

end:
mov	rax, 0
ret
