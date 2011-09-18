CC = gcc
FPATHS = -F/Library/Frameworks -F/System/Library/PrivateFrameworks
FW = -framework CoreFoundation -framework MobileDevice
INC = -I./include

all:
	@echo 'Initial Setup'
	@rm -rfv build
	@mkdir -p build
	@echo 'Building boot_mode'
	@$(CC) src/boot_mode.c -o build/boot_mode $(FPATHS) $(FW) $(INC)
	
clean:
	@echo 'Cleanup'
	@rm -rfv build