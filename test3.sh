#!/bin/bash

keysize="256"
key="tests/key3"
plainfile="tests/plaintext3"
cipherfile="tests/ciphertext3"
decryptfile="tests/decrypted3"

cmd_encrypt="./aes --verbose --keysize $keysize --mode encrypt --keyfile $key --inputfile $plainfile --outputfile $cipherfile"
cmd_decrypt="./aes --verbose --keysize $keysize --mode decrypt --keyfile $key --inputfile $cipherfile --outputfile $decryptfile"

echo $cmd_encrypt
$cmd_encrypt

echo $cmd_decrypt
$cmd_decrypt
