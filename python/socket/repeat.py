#!/usr/bin/python

import socket

socky = socket.socket()

host = socket.gethostname()
port = 12345

socky.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
socky.bind((host, port))

while True:
	socky.listen(5)
	client, addr = socky.accept()
	print addr, 'connected'
	client.send('Type "exit" to close the connection.\n')
	while True:
		data = client.recv(1024)
		if data == 'exit\n':
			break
		else:
			client.send(data)

	client.close()
