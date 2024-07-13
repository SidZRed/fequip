# fequip - File Equip tool

`fequip` is a command line tool designed for equipping files to enhance their storage and transfer capabilities. It includes methods for file compression using Huffman encoding and LZW, as well as file encryption and decryption. Files processed with `fequip` are stored with unique extensions for easy identification. The command line tool is implemented in C++ for better performance and security.

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

## Examples

### Compression

```bash
fequip -compress huffman <input_file>
```
Produces `<input_file>.cmp` and `<input_file>.map`.

### Encryption

```bash
fequip -encrypt cipher <input_file>
```
Produces `<input_file>.enc` and `<input_file>.key`.

### Decryption

```bash
fequip -decrypt cipher <input_file>.enc <input_file>.key
```
Produces `<input_file>.dec`.

## License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/SidZRed/fequip/blob/main/LICENSE) file for details.

## Credits

- Developed by [SidZRed](https://github.com/SidZRed)

New updates on this tool are to be released. Any new algorithms/ methods for the above are most welcome!

---
