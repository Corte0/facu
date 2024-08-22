# Define the FQBN (Fully Qualified Board Name) for your Arduino board
FQBN = arduino:avr:uno

# Define the output directory
BUILD_DIR = ./build

# Default target: Compile the sketch
all: compile

# Rule to compile the sketch
compile:
	arduino-cli compile --fqbn $(FQBN) --no-color --output-dir $(BUILD_DIR) .

# Rule to clean the build directory
clean:
	rm -rf $(BUILD_DIR)
