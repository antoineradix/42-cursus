extern ft_strlen
extern ft_strcpy
extern malloc
extern __errno_location

global ft_strdup

ft_strdup:
	call ft_strlen
	inc rax
	push rdi
	mov rdi, rax
	call malloc
	pop rdi
	cmp	rax, 0
	jz error
	mov rsi,rdi
	mov rdi,rax
	call ft_strcpy
	ret

error:
	neg rax
	mov rdx, rax
	call __errno_location
	mov [rax], rdx
	mov rax, -1
	ret