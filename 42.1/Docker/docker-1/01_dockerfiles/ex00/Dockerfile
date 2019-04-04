# docker build -t emacsalpine .
# docker run -it --rm --name="emacs" emacsalpine
FROM alpine

MAINTAINER aroger <aroger@student.42.fr>

RUN apk update && apk add emacs

ENTRYPOINT ["emacs"]

