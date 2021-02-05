section.text:
	global _ft_strcpy

_ft_strcpy:
	push rcx
	mov rcx, 0x0
	cmp rsi, byte 0x0
	jz _is_null

	_start_loop:
		mov dl, byte[rsi + rcx]			;	tmp = src[i]
		mov byte[rdi + rcx], dl			;	dst[i] = tmp
		cmp [rsi + rcx], byte 0x0		;	if (src[i] == NULL)
		jz _end_loop					;		break
		inc rcx							;	i++
		jmp _start_loop

	_end_loop:
	mov rax, rdi
	pop rcx
	ret

_is_null:
	mov rax, rsi
	pop rcx
	ret
