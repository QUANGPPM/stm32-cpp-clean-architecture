# STM32 Professional Firmware Template (C++)

A modern, decoupled, and hardware-agnostic firmware architecture for STM32 microcontrollers, designed for developers who want to move beyond monolithic vendor code and IDE lock-in.

## 🎯 Overview

This project serves as a practice template for structuring professional embedded systems. It demonstrates how to leverage **C++ Interfaces** and **Dependency Injection** to isolate application logic from hardware peripherals (STM32 HAL), ensuring high testability and portability.

## 🚀 Key Features

- **Layered Architecture**: Strict separation between `Application`, `Board (BSP)`, and `Drivers`.
- **Hardware Agnostic**: Application logic interacts only with abstract interfaces (`IGpioPin`), making it independent of the underlying MCU.
- **Modern Build System**: Full **CMake** integration for cross-compilation with `arm-none-eabi-gcc`.
- **CubeMX Friendly**: Seamlessly integrates with STM32CubeMX for hardware configuration without cluttering your business logic.
- **Professional Tooling**: Automated flashing via **OpenOCD** and professional debugging with **VSCode Cortex-Debug**.

## 📁 Project Structure

```text
├── Application/          # Business logic (Hardware-independent)
│   ├── Interfaces/       # C++ Abstract classes (Contracts)
│   ├── LedControl/       # Domain-specific components (Button, Led)
│   └── main.cpp          # Application entry point
├── Board/v1/             # Hardware-specific configuration
│   ├── CubeMX_Generated/ # Vendor code (HAL, CMSIS)
│   ├── board.cpp         # Hardware Factory (Instantiates drivers)
│   └── *.ld              # Linker script
├── Drivers/Peripherals/  # Concrete hardware implementations
│   └── gpio.cpp          # STM32 HAL implementation of IGpioPin
└── CMakeLists.txt        # Master build configuration
```

## 🛠️ Prerequisites

This project is verified with the following toolchain versions:
- **ARM GNU Toolchain**: `7.3.1 20180622` (GNU Tools for Arm Embedded Processors 7-2018-q2-update)
- **CMake**: `4.0.1`
- **Build Tools**: `GNU Make 4.4.1` (MinGW-w64)
- **OpenOCD**: `0.12.0` (xPack distribution)
- **Debugger**: ST-Link V2/V3

## 🔨 How to Build

1. **Configure the project**:
   ```bash
   cmake -B build -G "MinGW Makefiles"
   ```

2. **Compile**:
   ```bash
   cmake --build build
   ```

3. **Flash to MCU**:
   ```bash
   cmake --build build --target flash
   ```

## 🐞 Debugging in VSCode

1. Install the **Cortex-Debug** extension.
2. Select the **Cortex-Debug** configuration in the Run and Debug tab.
3. Press **F5** to start debugging. The system is pre-configured to handle GDB and OpenOCD integration.

## 📝 License
This project is for educational purposes. Feel free to use it as a base for your professional STM32 developments.
