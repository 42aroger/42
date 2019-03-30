FROM debian

RUN apt-get update && apt-get upgrade -y && apt-get install bzip2 ca-certificates -y

ENV TSV=3.7.1
ENV TS3SERVER_LICENSE=accept

ADD --chown=755 https://files.teamspeak-services.com/releases/server/${TSV}/teamspeak3-server_linux_amd64-${TSV}.tar.bz2 /opt

RUN tar xfv /opt/teamspeak3-server_linux_amd64-${TSV}.tar.bz2

ENTRYPOINT ["./teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh"]
