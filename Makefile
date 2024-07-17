.POSIX:
.PHONY: build clean

INCLUDE_DIRS = -Isources/efi \
			   -Isources/efi/defines \
			   -Isources/video_adapter \
			   -Isources/acpi2 \
			   -Isources/hii_loader \
			   -Isources/log \
			   -Isources/menu \
			   -Isources/kernel_arguments \
			   -I../platform \
			   -I../utils \
			   -I../elf_parser/

SOURCES = sources/main.c \
		  sources/log/log.c \
		  sources/menu/menu.c \
		  sources/video_adapter/video_adapter.c \
		  sources/acpi2/acpi2.c \
		  sources/hii_loader/hii_loader.c \
		  ../utils/utils.c \
		  ../elf_parser/elf_parser.c
OBJS = $(SOURCES:.c=.o)
DEPENDENCIES = $(SOURCES:.c=.d)

BUILD_TARGET = BOOTX64.EFI

CC = clang \
	 -target x86_64-unknown-windows

LDFLAGS = \
	-target x86_64-unknown-windows \
	-fuse-ld=lld-link \
	-Wl,-subsystem:efi_application \
	-Wl,-entry:EfiMain \
	-nostdlib


CFLAGS = \
	-std=c17 \
	-MMD \
	-Wall \
	-Wextra \
	-Wpedantic \
	-mno-red-zone \
	-ffreestanding

WRITE_ISO = ./build/write_gpt

build: $(BUILD_TARGET)

$(BUILD_TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)
	rm -rf build
	mkdir build
	mv $(BUILD_TARGET) build/$(BUILD_TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

-include $(DEPENDS)

clean:
	rm -rf build $(BUILD_TARGET) $(OBJS) $(DEPENDENCIES) DSKIMG.INF
