/**
 * file: 100-elf_header.c
 * Auth: Merga Chemeda
 */

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Alx student
 * @e_ident: make sure if its correct
 *
 * Description: pass my code
 */
void check_elf(unsigned char *e_ident)
{
int index;
for (index = 0; index < 4; index++)
{
if (e_ident[index] != 127 &&
e_ident[index] != 'E' &&
e_ident[index] != 'L' &&
e_ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF filen\n");
exit(98);
}
}
}

/**
 * print_magic - Prints the output of ELF
 * @e_ident: correct the error code
 *
 * Description: alx code
 */
void print_magic(unsigned char *e_ident)
{
int index;
printf(" Magic:  ");
for (index = 0; index < EI_NIDENT; index++)
{
printf("%02", e_ident[index]);
if (index == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}

/**
 * print_class - show me printout of ELF
 * @e_ident: Third class type
 */
void print_class(unsigned char *e_ident)
{
printf(" Class:			");
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
 * print_data - print out all ELF input
 * @e_ident: show me the correct output of elf input
 */
void print_data(unsigned char *e_ident)
{
printf("  Data:
switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
 * print_version - output of an ELF input
 * @e_ident: ouput data of input function
 */
void print_version(unsigned char *e_ident)
{
printf("  Version:
e_ident[EI_VERSION]);
switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf("  (current)\n");
break;
default:
printf("\n");
break;
}
}

/**
 * print_osabi - prints the OS/ABI of ELF
 * @e_ident: describe each function
 */
void print_osabi(unsigned char *e_ident)
{
printf("  OS/ABI:
switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_TRU64:
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}

/**
 * print_abi - the out put ELF which is ABI
 * @e_ident: explain the input of ELF ABI
 */
void print_abi(unsigned char *e_ident)
{
printf("  ABI Version:			%d\n",
e_ident[EI_ABIVERSION]);
}

/**
 * PRINT_TYPE - print all input of ELF
 * @e_type: kinds of ELF all
 * @e_ident: chek all files which provided by ELF header
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
	e_type >>= 8;
printf("  Type:			");
switch (e_type)
{
case ET_NONE:
printf("NONE (NONE)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", e_type);
}
}

/**
 * print_entry - the output of ELF input
 * @e_entry: a position of ELF
 * @e_ident: Explain ELF class
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf("  Entry point address:			");
if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}
if (e_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)e_entry);
else
printf("%#1x\n", e_entry);
}

/**
 * close_elf - shutdown an ELF file
 * @elf: explained file of All ELF content
 *
 * Description: if its not closed - exit code 98
 */
void close_elf(int elf)
{
if (close(elf) == -1)
{
dprintf(STDERR_FILENO, "Error: can't close fd %d\n", elf);
exit(98);
}
}

/**
 * main - explain all information in the file ELF
 * @argc: conclussion supllied to the input file
 * @argv: all array of input file
 *
 * Return: 0 on success
 * Description: if the program is not in ELF exit code 98
 *
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *header;
int o, r;

o = open(argv[1], O_RDONLY);
if (o == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
r = read(o, header, sizeof(Elf64_Ehdr));
if (r == -1)
{
free(header);
close_elf(o);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

check_elf(header->e_ident);
print("ELF Header:\n");
print_magic(header->e_ident);
print_class(header->e_ident);
print_data(header->e_ident);
print_version(header->e_ident);
print_osabi(header->e_ident);
print_abi(header->e_ident);
print_type(header->e_type, header->e_ident);
print_entry(header->e_entry, header->e_ident);

free(header);
close_elf(o);
return (0);
