run: mc
	build/bin/llvm-mc --triple x86_64-unknown-none-vsbf --filetype obj -o test.o test/simple.s

mc:
	ninja -C build llvm-mc

configure:
	mkdir -p build
	cmake -S llvm -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DLLVM_TARGETS_TO_BUILD=X86
