global	_ft_toupper
extern	_ft_isalpha

section	.text

_ft_toupper:
call	_ft_isalpha
cmp		rax, 0
je		end
cmp		rdi, 0x61
jl		end

sub	rdi, 0x20

end:
mov	rax, rdi
ret
