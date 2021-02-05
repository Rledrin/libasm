section.text:
	global _ft_read

_ft_read:
	push r8
	push r9
	push r10
	mov r8, rsi
	mov r9, rdi
	mov r10, rdx
	mov rax, 0x20000BD	;			0x2000000 == MacOS + 0xBD (fstat)
	syscall
	cmp rax, 9			;			if fstat return 9 == bad fd
	je _error
	cmp rax, 14
	je _error
	mov rsi, r8
	mov rdi, r9
	mov rdx, r10
	mov rax, 0x2000003	;		0x2000000 (MacOS ?)+ 0x4 (write syscall)
	syscall
	pop r8
	pop r9
	pop r10
	ret

_error:
mov rax, -1
pop r8
pop r9
pop r10
ret
