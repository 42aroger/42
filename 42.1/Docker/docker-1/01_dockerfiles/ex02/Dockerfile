# git clone https://bitbucket.org/railstutorial/sample_app_4th_ed.git app
# edit app/gemfile.lock, set rake to version "12.3.2"
# docker build -t ft-rails:on-build .
# docker build -t ex02 -f DockerfileGeneric .
# docker run -it --rm -p 3000:3000 ex02
FROM ruby

MAINTAINER aroger <aroger@student.42.fr>

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install build-essential nodejs sqlite3 -y

ONBUILD COPY app /opt/app

ONBUILD WORKDIR /opt/app

ONBUILD EXPOSE 3000
ONBUILD RUN bundle install
ONBUILD RUN rake db:migrate
ONBUILD RUN rake db:seed
