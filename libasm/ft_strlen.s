global	_ft_strlen

section	.text

_ft_strlen:
sub	rcx, rcx	; ecx = 0
not	rcx			; ecx = max(int)
sub	al, al		; mettre al a 0
cld				; direction flag = 0 (indexes augmentent)
repne	scasb	; loops til [edi] = al (=0) (scasb = scan byte string)
not	rcx			; reversing all bits of a negative number results in its absolute value - 1
dec	rcx			; rcx est maintenant egal au nombre d'iterations effectuees avant de rencontrer 0 dans rdi
mov	rax, rcx
ret
