# webserv
<img src="https://img.shields.io/badge/nginx-brightgreen" alt="NGINX"> <img src="https://img.shields.io/badge/HTTP-blue" alt="HTTP">  
This is when you finally understand why a URL starts with HTTP

## Summary
This project is about writing your ow HTTP server.  
You will be able to test it with an actual browser.  
HTTP is one of the most used protocols on the internet.  
Knowing its arcane will be useful, even if you won’t be working on a website.  

## Install
```sh
make         # comfile ./webserv
make clean   # remove temporary files
make fclean  # remove all files
make re      # make fclean and make
```

## Usage
```sh
./webserv
```

## Configuration file
__Example__
```sh
main {
	worker_connections    10000
	client_max_body_size  2M
	root                  /your/path/webserv
	default_error_root    serve/error/400.html
}

server {
	listen       80
	server_name  hello.com

	location / {
		root  /serve/html
		allowed_method  GET
		autoindex off
		index web.html index.html index.cpp
	}

	location /favicon.ico {
		root  /serve/html
		allowed_method  GET POST
		autoindex off
		index favicon.ico
	}

	location /error {
		root  /serve/error
		allowed_method  GET POST
		autoindex on
	}

	location .cpp {
		root  /serve/script
		allowed_method  GET POST DELETE
		autoindex off
	}
}
```
