global ft_strcpy

ft_strcpy:
	mov rax, rdi
	jz cpy_loop

cpy_loop:
	cmp byte [rsi], 0
	jz end
	mov dl, byte [rsi]
	mov byte [rdi], dl
	inc rsi
	inc rdi
	jmp cpy_loop

end:
	mov byte [rdi], 0
	ret