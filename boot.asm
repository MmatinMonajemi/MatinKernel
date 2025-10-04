[BITS 16]
[ORG 0x7C00]

start:
    cli                     ; غیرفعال‌سازی وقفه‌ها
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    call load_gdt
    call enter_protected_mode

hang:
    jmp hang

; -------------------------------
; بارگذاری GDT
load_gdt:
    lgdt [gdt_descriptor]
    ret

; -------------------------------
; سوئیچ به Protected Mode
enter_protected_mode:
    mov eax, cr0
    or eax, 1
    mov cr0, eax

    jmp CODE_SEG:init_pm

; -------------------------------
; کد Protected Mode
[BITS 32]
init_pm:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov esp, 0x90000

    call kernel_main        ; فراخوانی کرنل C
    jmp $

; -------------------------------
; GDT
gdt_start:
    dq 0x0000000000000000   ; null descriptor
    dq 0x00CF9A000000FFFF   ; code segment
    dq 0x00CF92000000FFFF   ; data segment

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

gdt_end:

CODE_SEG equ 0x08
DATA_SEG equ 0x10

times 510 - ($ - $$) db 0
dw 0xAA55
