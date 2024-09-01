# ft_transcendence

![JS Icon](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)
![HTML Icon](https://img.shields.io/badge/HTML-E34F26?style=flat&logo=html5&logoColor=white)
![CSS Icon](https://img.shields.io/badge/CSS-1572B6?style=flat&logo=css3&logoColor=white)
![Bootstrap Icon](https://img.shields.io/badge/Bootstrap-7952B3?style=flat&logo=bootstrap&logoColor=white)
![Three.js Icon](https://img.shields.io/badge/Three.js-000000?style=flat&logo=threedotjs&logoColor=white)
![Django Icon](https://img.shields.io/badge/Django-092E20?style=flat&logo=django&logoColor=white)
![PostgreSQL Icon](https://img.shields.io/badge/PostgreSQL-4169E1?style=flat&logo=postgresql&logoColor=white)
![NGINX Icon](https://img.shields.io/badge/NGINX-009639?style=flat&logo=nginx&logoColor=white)
![Docker Icon](https://img.shields.io/badge/Docker-2496ED?style=flat&logo=docker&logoColor=white)  
This is when you finally understand why a URL starts with HTTP

## Summary
This project is about doing something you’ve never done before.
Remind yourself the beginning of your journey in computer science.
Look at you now. Time to shine! 

## Install
```sh
make         # docker build & up
make clean   # docker down
make fclean  # docker down & remove all files
make re      # make fclean and make
```

## Usage
```sh
# When no configuration file is provided, the default configuration file will be used.

# Set environment variable
export IP_ADDRESS="your_ip_address"

# Chrome browser recommended
https://your_ip_address
```

## .env file
__Example__
```sh
POSTGRES_DB=
POSTGRES_USER=
POSTGRES_PASSWORD=
POSTGRES_HOST=
POSTGRES_PORT=

DJANGO_SETTINGS_MODULE=source.settings.prod

# Volume path
DB_VOLUME_PATH=${PWD}/data/db
WEB_VOLUME_PATH=${PWD}/data/web

# OAuth key
# You need to register a 42 application
SECRET_KEY=
FOURTY_TWO_CLIENT_ID=
FOURTY_TWO_REDIRECT_URI=https://${IP_ADDRESS}/
FOURTY_TWO_CLIENT_SECRET_KEY=
```
