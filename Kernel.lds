/**
 * @file Kernel.lds
 * @author LinhengXilan
 * @version 0.0.0.4
 * @date 2026-6-8
 */

OUTPUT_FORMAT("elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(Kernel)

PHDRS {
    text     PT_LOAD  FLAGS(5);
	rodata   PT_LOAD  FLAGS(4);
    data     PT_LOAD  FLAGS(6);
}

SECTIONS
{
	. = 0;
	.text :
	{
		_text = .;
		*(.text)
		_etext = .;
	} : text
	. = ALIGN(8);
	.rodata :
	{
		_rodata = .;
		*(.rodata)
		_erodata = .;
	} : rodata
	.data :
	{
		_data = .;
		*(.data)
		_edata = .;
	} : data
	.bss :
	{
		_bss = .;
		*(.bss)
		_ebss = .;
	} : data
	_end = .;
}