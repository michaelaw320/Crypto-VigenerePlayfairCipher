# Crypto-VigenerePlayfairCipher

--HELP--
USAGE: VigenerePlayfairCipher.exe
--help, -h 	: Print this help
--encrypt, -e 	: Encrypt Mode
--decrypt, -d 	: Decrypt Mode
--binary, -b 	: Operates in binary mode, algo must be vig_ext
--input <input_file>, -i <input_file> : Specify input file
	Use "stdin" for keyboard input
	
--output <output_file>, -o <output_file> : Specify input file
	Use "stdout" for screen output
	
--key <string>, -k <string> : Key for encryption/decryption (max 25 chars)

--algorithm <string>, -a <string> : Available algorithm: vig_std, vig_ext, playfair
	vig_std  : Vigenere Cipher Standard (26 Alphabets)
	vig_ext  : Vigenere Cipher Extended (256 ASCII Chars)
	playfair : Playfair Cipher
	
--format <string>, -f <string> : Specify output format: normal, wo_space, five
	normal   : Same as input
	wo_space : Without spaces	five     : Group five by five
--****--
