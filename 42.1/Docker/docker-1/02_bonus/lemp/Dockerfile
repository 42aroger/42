FROM debian

MAINTAINER aroger <aroger@student.42.fr>

ENV DEBIAN_FRONTEND=noninteractive

#Update and upgrade + install supervisor + MariaDB
RUN apt-get update && apt-get upgrade -y && apt-get install supervisor mariadb-server mariadb-client -y

#Install and start Nginx + php7.0-fpm and dependencies
RUN apt-get install nginx php7.0-fpm php7.0-mysqlnd php7.0-curl php7.0-gd php7.0-intl php7.0-imap php7.0-mcrypt php7.0-sqlite php7.0-xmlrpc -y

# Nginx configuration
#ADD nginx.conf /etc/nginx/
ADD default /etc/nginx/sites-available/

#Supervisor configuration files
ADD supervisord.conf /etc/supervisor/
ADD supervisor-lemp.conf /etc/supervisor/conf.d/

#Add phpinfo as index.php
ADD index.php /var/www/html/

# Clean up
RUN apt-get clean

EXPOSE 80 443 3306

CMD ["supervisord"]