global ft_strcmp

ft_strcmp:
	cmp byte [rdi], 0
	jz end
	cmp byte [rsi], 0
	jz end
	cmpsb
	jz ft_strcmp
	dec rdi
	dec rsi
	jz end

end:
	movzx rax, byte [rdi]
	movzx rcx, byte [rsi]
	sub		rax, rcx
	ret