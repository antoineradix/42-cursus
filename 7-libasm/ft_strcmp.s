global ft_strcmp

ft_strcmp:
	cmp byte[rdi], 0
	je exit
	cmp byte[rsi], 0
	je exit
	inc rdi
	inc rsi
	je ft_strcmp
	dec rdi
	dec rsi

exit:
	movzx rax, byte[rdi]
	movzx rcx, byte[rsi]
	sub	rax, rcx
	ret
