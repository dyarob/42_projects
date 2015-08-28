global	_ft_strcat

section	.text

_ft_strcat:		; ici on positionne rdi a la fin de la chaine de destination
cld
cmp	BYTE[rdi], 0
je	concat
add	rdi, 1
jmp	_ft_strcat

concat:
cmp	BYTE[rsi], 0	; condition de sortie
je	end
movsb				; moves [rsi] into [rdi] and increments
jmp	concat

end:
ret
