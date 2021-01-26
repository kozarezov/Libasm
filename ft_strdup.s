    section .text
    global _ft_strdup
    extern _malloc
    extern _ft_strlen
    extern _ft_strcpy
_ft_strdup:
    push rdi ; put rdi pointer in stack
    call _ft_strlen ; strlen in rax
    mov rdi, rax ; rax in rdi
    inc rdi ; rdi++ for '\0'
    call _malloc ; malloc rdi
    cmp rax, 0 ; memory is not allocated
    je end
    mov rdi, rax ; malloc memory in rdi
    pop rsi ; take pointer in rsi
    call _ft_strcpy
end:
    ret
 