    section .text
    global _ft_write
    extern ___error

_ft_write:
    mov rax, 0x02000004 ; syscall write 0x02000004
    syscall ; call write
    jc error ; if error go to error
    ret

error:
    mov rdx, rax ; save rax
    call ___error ; call errno 
    mov [rax], rdx ; write error in pointer to errno
    mov rax, -1 ; error write = - 1
    ret
