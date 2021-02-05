section.text:
	global _ft_write

_ft_write:
	push r8
	push r9
	cmp rsi, byte 0x0
	je _error
	mov r8, rsi
	mov r9, rdx
	mov rax, 0x20000BD	;			0x2000000 == MacOS + 0xBD (fstat)
	syscall
	cmp rax, 9			;			if fstat return 9 == bad fd
	je _error
	mov rsi, r8
	mov rdx, r9
	mov rax, 0x2000004	;			0x2000000 == MacOS + 0x04 (write)
	syscall
	pop r8
	pop r9
	ret

_error:
	mov rax, -1			;			return(-1)
	pop r8
	pop r9
	ret
