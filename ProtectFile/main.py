import os
import hashlib
import stat
import sys
from time import time, sleep

def read_template (path):
	os.chmod(path + '/template.tbl', stat.S_IRWXU)	
	sys.stdin = open('template.tbl', 'r')
	
	tree = os.walk(path) 
	dir_files = []
	for d, dirs, files in tree:
		for f in files:
			dir_files.append(f)

	file_list = []
	my_hash = input()
	n = int(input())

	for i in range(n):
	    file_list.append(input())

	os.chmod(path + '/template.tbl', stat.S_ENFMT)

	return my_hash, file_list, dir_files


def change_mode_file (path, file_list, dir_files, mode):
	for file in dir_files:
		for i in file_list:
			if file == i:
				os.chmod(path + '/' + i, mode)


def unlock_file(path, password):
	my_hash, file_list, dir_files = read_template(path)

	if hashlib.sha224(b""+password.encode('utf-8')).hexdigest() != my_hash:
		print ("wrong password")
		return
	
	change_mode_file (path, file_list, dir_files, stat.S_IRWXU)


def main ():
	path = os.getcwd()
	mode = input('lock/unlock file?\n')

	if mode == 'lock':
		my_hash, file_list, dir_files = read_template(path)
		change_mode_file(path, file_list, dir_files, stat.S_ENFMT)
	else:
		if mode == 'unlock':
			password = input('please enter password\n')
			unlock_file(path, password)


if __name__ == "__main__":
    main()
