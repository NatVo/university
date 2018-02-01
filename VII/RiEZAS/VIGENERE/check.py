ALPHABET = 'абвгдежзиклмнопрстуфхцчшщъыьэюяАБВГДЕЖЗИКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ'


if __name__ == '__main__':

	numbers = []
	for i in ALPHABET:
		numbers.append(ord(i))

	print(max(numbers))
	print(min(numbers))

	print(numbers)