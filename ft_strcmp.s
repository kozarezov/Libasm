    section .text
    global _ft_strcmp
_ft_strcmp:
    mov rcx, 0
while:
    movsx rax, byte [rdi + rcx] ; copy 8 bit (byte rdi) in 16 bit (rax)
    movsx rbx, byte [rsi + rcx] ; copy 8 bit (byte rdi) in 16 bit (rax)
    inc rcx ; rcx++
    cmp rax, 0 ; rax == '\0'?
    je end
    cmp rbx, 0 ; rbx == '\0'?
    je end
    cmp rax, rbx ; rax == rbx?
    je while
end:
    cmp rax, rbx ; rax == rbx?
    je equal
    cmp rax, rbx ; rax > rbx?
    jg greater
    cmp rax, rbx ; rax < rbx?
    jl less
equal:
    mov rax, 0 ; rax == rbx
    ret
greater:
    mov rax, 1 ; rax > rbx
    ret
less:
    mov rax, -1 ; rax < rbx
    ret
