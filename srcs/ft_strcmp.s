section.text:
	global _ft_strcmp

_ft_strcmp:
	push rcx
	mov rcx, 0x0
	cmp rsi, 0x0
	jz _is_null
	cmp rdi, 0x0
	jz _is_null

	_start_loop:
		inc rcx
		mov dl, [rsi + rcx]
		mov al, [rdi + rcx]
		cmp dl, al
		ja _end_neg
		cmp dl, al
		jb _end_pos
		cmp al, 0x0
		jz _end_null
		cmp dl, al
		je _start_loop

	_end_loop:
	mov	rax, 0
	pop rcx
	ret

_end_null:
	cmp dl, 0x0
	jz _end_loop
	jmp _start_loop

_end_neg:
	mov rax, - 1
	pop rcx
	ret
_end_pos:
	mov rax, 1
	pop rcx
	ret

_is_null:
	pop	rcx
	mov rax, [rsi]
	sub rax, [rdi]
	ret
