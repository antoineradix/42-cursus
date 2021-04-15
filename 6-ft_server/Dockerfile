FROM	debian:buster

LABEL	maintainer="anradix@student.42.fr"
LABEL	build_date="2020-06-04"

RUN	apt-get -y update && apt-get -y upgrade

RUN	apt-get install -y \
	wget \
	nginx \
	mariadb-server mariadb-client \ 
	php-fpm php-mysql 

RUN	wget https://wordpress.org/latest.tar.gz 
RUN	wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz

RUN	tar -xzvf latest.tar.gz && \
	rm latest.tar.gz && \
	mv wordpress /var/www/html/wordpress && \
	chown -R www-data:www-data /var/www/html/wordpress/ &&\
	chmod -R 755 /var/www/html/wordpress/ && \
	rm var/www/html/index.nginx-debian.html && rm /var/www/html/wordpress/wp-config-sample.php

RUN	tar -xzvf phpMyAdmin-5.0.1-english.tar.gz && \
	rm phpMyAdmin-5.0.1-english.tar.gz && \
	mv phpMyAdmin-5.0.1-english /var/www/html/phpMyadmin

RUN	openssl req -newkey rsa -nodes -keyout /etc/ssl/private/ssl_key.key \
	-x509 -out /etc/ssl/certs/ssl_certificate.crt \
	-subj "/C=FR/ST=Paris/L=Paris/O=42/OU=42/CN=anradix"

COPY	./srcs/default ./etc/nginx/sites-available/default
COPY	./srcs/infos.php ./var/www/html
COPY	./srcs/wp-config.php ./var/www/html/wordpress/wp-config.php
COPY	./srcs/db_wordpress db_wordpress

EXPOSE	80 443

RUN	service mysql start && mysql -u root < db_wordpress

CMD	service nginx restart \
	&& service mysql start \
	&& service php7.3-fpm start \
	&& tail -f /dev/null
