# فایل‌ها
BOOTLOADER = bootloader/boot.asm
KERNEL = kernel/kernel.c
OUTPUT = matin_kernel.bin

# ابزارها
NASM = nasm
GCC = gcc
LD = ld
QEMU = qemu-system-x86_64

# قوانین ساخت
all: $(OUTPUT)

boot.o: $(BOOTLOADER)
    $(NASM) -f elf32 $< -o $@

kernel.o: $(KERNEL)
    $(GCC) -m32 -ffreestanding -c $< -o $@

$(OUTPUT): boot.o kernel.o
    $(LD) -m elf_i386 -T link.ld -o $@ boot.o kernel.o

run: $(OUTPUT)
    $(QEMU) -drive format=raw,file=$(OUTPUT)

clean:
    rm -f *.o $(OUTPUT)
