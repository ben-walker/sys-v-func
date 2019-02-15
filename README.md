# sys-v-func
Time how long it takes to read a file.
- Supply a file of whatever size (contents don't matter)
- Specify how many bytes to read at a time
- Choose how it'll be read, either with Unix system calls (`open`/`read`/`close`) or C functions (`fopen`/`fread`/`fclose`)
- And BOOM, `unixio` will tell you how long it took

### Running `unixio`
1. Run `make` in the base directory
2. Type `./unixio`

### Usage
- **`./unixio -f filename -b bytes -t type`**
- Where:
  - `filename` is the name of a file to read
  - `bytes` is the number of bytes to read each time `read` or `fread` is called (greater than 0 please)
  - `type` is either 0 (to read the file with C functions) or 1 (to use the Unix equivalents)

### Quick Automated Testing
1. `truncate -s 1M filename`
2. `chmod u+x t.sh`
3. `./t.sh`
- The above will read `filename` using 1, 256, 512, 1024, 2048, and 4096 bytes, in C and Unix variants
