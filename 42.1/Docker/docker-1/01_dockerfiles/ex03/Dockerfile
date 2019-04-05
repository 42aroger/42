# docker build -t gitssh .
# docker run -it --rm -p 8080:80 -p 8022:22 -p 8443:443 --privileged gitssh
FROM debian:stable-slim

MAINTAINER aroger <aroger@student.42.fr>

RUN apt-get update && apt-get upgrade -y && apt-get install ca-certificates openssh-server curl postfix -y

RUN curl -O https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh && chmod +x script.deb.sh && bash script.deb.sh && apt-get install gitlab-ce 

EXPOSE 443 80 22

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && tail -f /dev/null
