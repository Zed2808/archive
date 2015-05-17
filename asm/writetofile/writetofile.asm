global _start

section .data
	str:	db 'Hello World!',0xA
	strlen:	equ $-str

section .text
_start:
	pop	ebx		; argc (argument count)
	pop	ebx		; argv[0] (program name)
	pop	ebx		; argv[1] (first real arg, in this case file name)

	mov	eax, 8		; sys_creat
				; file name already popped and stored in ebx
	mov	ecx, 00644Q	; read/write permissions in octal (rw-rw-rw-)
	int	0x80		; call the kernel
				; file descriptor now stored in eax

	test	eax, eax	; make sure file descriptor is valid
	js	skipwrite	; check for sign flag (meaning file descriptor is < 0)

	call filewrite

skipwrite:
	mov	ebx, eax	; if there was an error, save errno in ebx
	mov	eax, 1		; sys_exit
	int	0x80

filewrite:
	mov	ebx, eax	; move file descriptor into ebx
	mov	eax, 4		; sys_write
	mov	ecx, str	; put address of str into ecx
	mov	edx, strlen	; put value of strlen into edx because it's a constant (defined with equ)
	int	0x80

	mov	eax, 6		; sys_close
				; ebx already contains file descriptor
	int	0x80
	ret
