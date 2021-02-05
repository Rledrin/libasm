section.text:
	global _ft_strlen

_ft_strlen:
	mov rax, 0x0 ;					rax = 0 ||||| rax is the return value 

	_start_loop:
		cmp byte [rdi + rax], 0x0 ;	if (rdi+rax == '\0')
		je _end_loop ;					jump to flag _end_loop
		inc rax	;					rax++
		jmp _start_loop ;			jump to start

	_end_loop:
	ret
