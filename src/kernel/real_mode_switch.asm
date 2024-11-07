section .text
global switch_to_real_mode

switch_to_real_mode:
    ; Save registers
    pusha

    ; Switch to real mode
    cli
    mov eax, cr0
    and eax, 0xFFFFFFFE
    mov cr0, eax
    jmp .flush_pipeline
.flush_pipeline:
    ; Set up segment registers for real mode
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov sp, 0x7C00

    ; Call BIOS interrupt to switch video mode
    mov ax, 0x13
    int 0x10

    ; Switch back to protected mode
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    jmp .flush_pipeline_pm
.flush_pipeline_pm:
    ; Restore registers
    popa
    ret
