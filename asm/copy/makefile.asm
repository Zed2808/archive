global _start

section .text
_start:
	pop	ebx		; argc
	pop	ebx		; argv[0], program name
	pop	ebx		; argv[1], first real arg (name of file to copy)

	mov	eax, 8		; sys_creat
				; file name already popped and stored in ebx
	mov	ecx, 00644Q	; read/write permissions in octal (rw- r-- r--)
	int	0x80		; call the kernel
				; file descriptor now stored in eax

	mov	ebx, eax	; move file descriptor in eax to ebx
	mov	eax, 1		; sys_exit
	int	0x80
