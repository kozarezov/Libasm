    section .text
    global _ft_read
    extern ___error

_ft_read:
    mov rax, 0x02000003 ; syscall read 0x02000003
    syscall ; call read
    jc error ; if error go to error
    ret

error:
    mov rdx, rax ; save rax
    call ___error ; call errno 
    mov [rax], rdx ; write error in pointer to errno
    mov rax, -1 ; error read = - 1
    ret
