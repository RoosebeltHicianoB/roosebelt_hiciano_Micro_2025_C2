# ESP32 FreeRTOS Timer Project

This project demonstrates how to use FreeRTOS timers on the ESP32 platform. It includes the necessary files to create, manage, and utilize a FreeRTOS timer within an embedded application.

## Project Structure

```
esp32-freertos-timer
├── src
│   ├── main.c            # Entry point of the application
│   └── freertos_timer.c  # Implementation of FreeRTOS timer functionality
├── include
│   └── freertos_timer.h   # Header file for timer functions and types
├── CMakeLists.txt        # CMake configuration file
└── README.md             # Project documentation
```

## Getting Started

### Prerequisites

- ESP32 development board
- ESP-IDF installed
- CMake and Ninja build system

### Building the Project

1. Clone the repository:
   ```
   git clone <repository-url>
   cd esp32-freertos-timer
   ```

2. Set up the ESP-IDF environment:
   ```
   . $IDF_PATH/export.sh
   ```

3. Build the project:
   ```
   idf.py build
   ```

### Flashing the Project

To flash the project onto your ESP32 board, use the following command:
```
idf.py -p <your-port> flash
```

Replace `<your-port>` with the appropriate serial port for your ESP32 device.

### Usage

Once the project is flashed, the FreeRTOS timer will start running. You can modify the timer duration and callback functionality in `freertos_timer.c` to suit your application needs.

### Contributing

Feel free to submit issues or pull requests if you have suggestions or improvements for this project.

### License

This project is licensed under the MIT License. See the LICENSE file for more details.