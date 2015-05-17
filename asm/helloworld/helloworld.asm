section .text
global _start

_start:
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, message
	mov	edx, length
	int	0x80

	mov	eax, 1
	int	0x80


section .data

message db 'Hello World',0xa
length equ $ - message
