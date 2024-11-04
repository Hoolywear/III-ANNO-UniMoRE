g++ -v -o hw hw.o
# esempio di output (alla fine):
# > [...] -build-id -eh-frame-hdr -m elf_x86_64 \
# > -hash-style=gnu -as-needed \
# > -dynamic-linker /lib64/ld-linux-x86-64.so.2 \
# > ...
# > /usr/lib/x86_64-linux-gnu/crtn.o
ld -build-id -eh-frame-hdr [...] # invoco con tutti i parametri trovati,
                                 # di norma escludendo i plugin
