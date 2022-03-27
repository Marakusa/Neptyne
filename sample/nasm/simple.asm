section .data

section .text
	global 	_start

_start:
	call    _main
	mov     eax, 1                  ; syscall = 1 == exit
	mov     ebx, 0                  ; fd = 0 == stdin
	int     80h                     ; Call kernel

_main:
	push    rbp                     ; Save address of previous stack frame
	mov     rbp, rsp                ; Address of current stack frame
		
	mov  	DWORD [rbp-0x1], 21

    mov     eax, 0					  ; Set return value from this function to 0
	pop		rbp						  ; Cleanup the stack
	ret								  ; Return