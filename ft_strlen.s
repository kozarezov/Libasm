    section .text
	global _ft_strlen
_ft_strlen:
	mov rax, 0 ; rax = 0
while:
    cmp byte [rdi + rax], 0 ; str[rax] == '\0'?
    je exit ; if true
    inc rax ; rax++
    jmp while ; if false
exit:
    ret ; return rax
