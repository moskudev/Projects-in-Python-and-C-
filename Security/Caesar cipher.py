from ast import Num


message = input("Message: ")

key = int(input('Key (0 to 25: '))

mode = input('Encrypt or Decrypt: (write your choice)')
mode = mode.lower()

LETTERS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

translated = ''

message = message.upper()

for symbol in LETTERS:
    if symbol in LETTERS:
        num = LETTERS.find(symbol)
        if mode == 'encrypt':
            num = num + key
        elif mode == 'decrypt':
            num = num - key

        if num >= len(LETTERS):
            num = num - len(LETTERS)
        elif num <0:
            num = num + len(LETTERS)

        translated = translated + LETTERS[num]

    else:
        translated = translated + LETTERS[num]

    print(translated)