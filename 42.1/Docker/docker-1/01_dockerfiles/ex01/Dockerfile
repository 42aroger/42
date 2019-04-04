# docker build -t teamspeak .
# docker run -it --name="teamspeak_server" -p "9987:9987/udp" -p 10011:10011 -p 30033:30033 teamspeak
FROM debian

MAINTAINER aroger <aroger@student.42.fr>

RUN apt-get update && apt-get upgrade -y && apt-get install bzip2 ca-certificates -y

ENV TSV=3.7.1
ENV TS3SERVER_LICENSE=accept

ADD --chown=755 https://files.teamspeak-services.com/releases/server/${TSV}/teamspeak3-server_linux_amd64-${TSV}.tar.bz2 /opt

RUN tar xfv /opt/teamspeak3-server_linux_amd64-${TSV}.tar.bz2

#Port teamspeak + serverquery + file transfert
EXPOSE 9987 10011 30033

ENTRYPOINT ["./teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh"]
