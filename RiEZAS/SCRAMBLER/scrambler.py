import numpy as np
import random

'''
def shift_register_list(register, element):
	register.pop()
	register.reverse()
	register.append(element)
	return register.reverse()
'''

def construct_scrambler():
	shift_reg_length, xor_1, xor_2 = input_elements()
	return Scrambler(xor_1, xor_2, shift_reg_length)
	
	
def ss_scrambling(scrambler, signal):

	print('\n_____________________________________________')
	print('|САМОСИНХРОНИЗИРУЮЩИЙСЯ СКРЕМБЛЕР/ДЕСКРЕМБЛЕР|')
	print('_____________________________________________\n')
		
	encode_signal = scrambler.ss_scrambler_descrambler(signal, 'scrambler')
	print('\nИСХОДНЫЙ СИГНАЛ: ', signal)
	print('СКРЕМБЛИРОВАННЫЙ СИГНАЛ: ', encode_signal, '\n')

	decode_signal = scrambler.ss_scrambler_descrambler(encode_signal, 'descrembler')
	print('\nСКРЕМБЛИРОВННЫЙ СИГНАЛ: ', encode_signal)
	print('ДЕСКРЕМБЛИРОВАННЫЙ СИГНАЛ: ', decode_signal, '\n')

def addit_scrambling(scrambler, signal, register):

	print('\n________________________________')
	print('|АДДИТИВНЫЙ СКРЕМБЛЕР/ДЕСКРЕМБЛЕР|')
	print('__________________________________\n')
		
	encode_signal = scrambler.addit_scrambler_descrambler(signal, register)
	print('\nИСХОДНЫЙ СИГНАЛ: ', signal)
	print('СКРЕМБЛИРОВАННЫЙ СИГНАЛ: ', encode_signal, '\n')

	decode_signal = scrambler.addit_scrambler_descrambler(encode_signal, register)
	print('\nСКРЕМБЛИРОВННЫЙ СИГНАЛ: ', encode_signal)
	print('ДЕСКРЕМБЛИРОВАННЫЙ СИГНАЛ: ', decode_signal, '\n')


def input_elements():
	print('\nПАРАМЕТРЫ РЕГИСТРА:')
	shift_reg_length = int(input('\nДЛИНА РЕГИСТРА: '))
	flag = False
	while (flag == False): 	
		xor_1 = int(input('xor_1: '))
		xor_2 = int(input('xor_2: '))
		flag = True

		if (xor_1 > shift_reg_length or xor_1 < 1):
			flag = False
		if (xor_2 > shift_reg_length or xor_2 < 1):
			flag = False
						 
	return shift_reg_length, xor_1, xor_2

def input_signal():
	signal = ''
	choose = int(input('1 - ВВОД СИГНАЛА; 2 - СГЕНЕРИРОВАТЬ СИГНАЛ '))
	print()
	if (choose == 1):
		signal = input('СИГНАЛ: ')
	elif (choose == 2):
		length = int(input('ДЛИНА СИГНАЛА: '))
		for i in range(length):
			signal += str(random.randint(0, 1))
		print('СГЕНЕРИРОВАННЫЙ СИГНАЛ: ', signal)
	else: 
		print('НЕКОРРЕКТНЫЙ ВВОД!')
	return signal

def input_register(reg_length):
	
	r_str = input('НАЧАЛЬНОЕ СОСТОЯНИЕ РЕГИСТРА: ')
	while (len(r_str) != reg_length):
		print('НАЧАЛЬНОЕ СОСТОЯНИЕ РЕГИСТРА ЗАДАНО НЕКОРРЕКТНО')
		r_str = input('НАЧАЛЬНОЕ СОСТОЯНИЕ РЕГИСТРА: ')
	register = []
	for i in r_str:
		register.append(int(i))
	register = np.array(register)
	return register

def shift_register_np(register, element):	
	register = np.delete(register, register.size - 1)
	register = np.flip(register, axis = 0)
	register = np.append(register, element)
	return np.flip(register, axis = 0)

class Scrambler():

	def __init__(self, xor_1, xor_2, shift_reg_length = None):
		#self.signal = signal
		#self.register = [0] * shift_reg_length
		#self.register = np.zeros((shift_reg_length,), dtype = np.int)
		self.shift_reg_length = shift_reg_length
		self.xor_1 = xor_1 - 1
		self.xor_2 = xor_2 - 1
		
	def ss_scrambler_descrambler(self, signal, flag):
		register = np.zeros((self.shift_reg_length,), dtype = np.int)
		code_signal = ''

		for i in range(0, len(signal)):	
			print(register)
			b = bool(int(signal[i])) ^ bool(register[self.xor_1]) ^ bool(register[self.xor_2])
			#print ('s[', i, '] ', signal[i], ' bool(s[', i, ']) ', bool(int(signal[i])))
			#print ('reg[', self.xor_1, '] ', register[self.xor_1], ' bool(reg[', self.xor_1, ']) ', bool(register[self.xor_1]))
			#print ('reg[', self.xor_2, '] ', register[self.xor_2], ' bool(reg[', self.xor_2, ']) ', bool(register[self.xor_2]))	
			code_signal += str(int(b))
			#register = shift_register_np(register, None)
			if (flag == 'scrambler'):
				#register[0] = int(b)		
				register = shift_register_np(register, int(b))
			elif (flag == 'descrembler'):
				#register[0] = int(signal[i])
				register = shift_register_np(register, int(signal[i]))
		return code_signal

	
	def addit_scrambler_descrambler(self, signal, register):
		code_signal = ''
		for i in range(0, len(signal)):
			print(register)
			xor_reg = bool(register[self.xor_1]) ^ bool(register[self.xor_2])
			b = bool(int(signal[i])) ^ xor_reg
			code_signal += str(int(b))
			register = shift_register_np(register, int(xor_reg))
								
		return code_signal	
		

if __name__ == '__main__':
	#shift_reg_length, xor_1, xor_2 = input_elements()
	#scrambler = Scrambler(3, 5, 5)
	print('\nСАМОСИНХРОНИЗИРУЮЩИЙСЯ СКРЕМБЛЕР/ДЕСКРЕМБЛЕР')
	print('============================================')
	shift_reg_length, xor_1, xor_2 = input_elements()
	scrambler =  Scrambler(xor_1, xor_2, shift_reg_length)
	
	signal = input_signal()
	ss_scrambling(scrambler, signal)

	print('\nАДДИТИВНЫЙ СКРЕМБЛЕР/ДЕСКРЕМБЛЕР')
	print('====================================')
	shift_reg_length, xor_1, xor_2 = input_elements()
	scrambler =  Scrambler(xor_1, xor_2, shift_reg_length)
	
	register = input_register(shift_reg_length)
	signal = input_signal()
	addit_scrambling(scrambler, signal, register)
	#print(register)
	'''
	register = np.array([1, 0, 0, 1, 0])
	encode_string = scrambler.addit_scrambler_descrambler('111111110000000', register)
	print(encode_string, '\n')
	
	decode_string = scrambler.addit_scrambler_descrambler(encode_string, register)
	print(decode_string)
	'''
