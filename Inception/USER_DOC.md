User documentation This file must explain, in clear and simple terms, how an end user or administrator can:
	◦	Understand what services are provided by the stack.
	◦	Start and stop the project.
	◦	Access the website and the administration panel.
	◦	Locate and manage credentials.
	◦	Check that the services are running correctly.


Makefile will check if the persistence folders exist, if not it will create them for you
Makefile will also check if you have the right secrets files in the secrets folder.
 -> if not, make will fail with the right error message.
 -> You need to have the right secret files stored in the secrets folder.
 -> In case any file is empty, this program will assign a dummy password 1234 to the correspondant user (user, admin or root)
