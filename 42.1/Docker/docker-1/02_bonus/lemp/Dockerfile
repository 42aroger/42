FROM debian

#Update and upgrade + install MariaDB + systemd
RUN apt-get update && apt-get upgrade -y && apt-get install systemd mariadb-server mariadb-client -y

#Install and start Nginx
RUN apt-get install nginx -y && systemctl start nginx.service

#Install php5-fpm
RUN apt-get install php5-fpm -y