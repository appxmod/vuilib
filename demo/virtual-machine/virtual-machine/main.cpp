#include "vasm-vm.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	VASM::Compiler Compiler(L"./main.S", VASM::CompilerMode::FromFile);
	Compiler.Compile(L"./MAIN.O");

	VASM::VASMInterpreter Interpreter(L"./ROM.DISK", VASM::VirtualMachineConfig{1024 * 1024, 1024 * 1024 * 1024},
									  new VASM::VASMGPU);
	Interpreter.RunVASMFile(L"./MAIN.O");

	return 0;
}