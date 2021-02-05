section.text:
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup:
	cmp rdi, byte 0x0
	je _error1
	call _ft_strlen
	inc rax
	push rdi
	mov rdi, rax
	call _malloc
	cmp rax, 0x0
	je _error2
	pop rdi
	push rsi
	mov rsi, rdi
	mov rdi, rax
	call _ft_strcpy
	pop rsi
	ret

_error1:
mov rax, 0x0
ret

_error2:
mov rax, 0x0
pop rdi
ret
