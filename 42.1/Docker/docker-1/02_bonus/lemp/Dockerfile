FROM debian

#Update and upgrade + install MariaDB + systemd
RUN apt-get update && apt-get upgrade -y && apt-get install systemd mariadb-server mariadb-client -y

#Install and start Nginx
RUN apt-get install nginx -y && ./etc/init.d/nginx start

#Install php5-fpm + php7 dependencies for mariadb
RUN apt-get install php7.0-fpm php7-mysqlnd php7-curl php7-gd php7-intl php-pear php7-imagick php7-imap php7-mcrypt php7-memcache php7-intl php7-pspell php7-recode php7-snmp php7-sqlite php7-tidy php7-xmlrpc php7-xsl -y

#Restart nginx
RUN ./etc/init.d/nginx restart