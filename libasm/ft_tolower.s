global	_ft_tolower
extern	_ft_isalpha

section	.text

_ft_tolower:
call	_ft_isalpha
cmp		rax, 0
je		end
cmp		rdi, 0x61
jge		end

add	rdi, 0x20

end:
mov	rax, rdi
ret
