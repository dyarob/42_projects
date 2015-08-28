global	_ft_isalnum
extern	_ft_isalpha, _ft_isdigit

section	.text

_ft_isalnum:
call	_ft_isalpha
cmp	rax, 0
je	end
ret

end:
call	_ft_isdigit
ret
