ENTRY(init_pm)

SECTIONS {
  . = 0x100000; /* آدرس بارگذاری کرنل در حافظه (1MB) */

  .text : {
    *(.text)
  }

  .rodata : {
    *(.rodata)
  }

  .data : {
    *(.data)
  }

  .bss : {
    *(.bss)
    *(COMMON)
  }
}
