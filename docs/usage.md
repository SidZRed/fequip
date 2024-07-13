## Installation

### Debian-based systems (using apt)

```bash
sudo apt update
sudo apt install fequip
```

### macOS (using Homebrew)

```bash
brew update
brew install fequip
```

## Usage
General usage:
```bash
fequip -command -type <input_file>
```

For help in using the tool, run:
```bash
fequip -help
```

### Commands
A few commands are available for equipping on the files : 

- `compress`: Compresses the input file using specified compression algorithm.
- `encrypt`: Encrypts the input file using specified encryption cipher.
- `decrypt`: Decrypts the encrypted input file using specified decryption cipher.

### Types

- `-compress`: Specify compression algorithm (`-huffman` or `-lzw`).
- `-encrypt`: An encryption cipher is used ( `-cipher`)
