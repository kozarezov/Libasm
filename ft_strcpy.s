    section .text
    global _ft_strcpy
_ft_strcpy:
    mov rcx, 0 ; rсx = 0
while:
    mov bh, byte [rsi + rcx] ; save char in rsi
    cmp bh, 0 ; BH == '\0'?
    je exit 
    mov byte [rdi + rcx], bh ; put char in rdi
    inc rcx ; rcx++
    jmp while
exit:
    mov byte [rdi + rcx], 0 ; '\0'
    mov rax, rdi ; rax = rdi
    ret ; return rax
