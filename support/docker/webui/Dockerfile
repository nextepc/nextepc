FROM node:carbon

MAINTAINER NextEPC <help@nextepc.com>

ARG PACKAGE=nextepc
ARG VERSION=0.3.3

RUN set -e; \
    cd /usr/src; \
    rm -rf ./$PACKAGE; \
    curl -SLO "https://github.com/nextepc/$PACKAGE/archive/v$VERSION.tar.gz"; \
    tar -xvf v$VERSION.tar.gz; \
    mv ./$PACKAGE-$VERSION/ ./$PACKAGE;

WORKDIR /usr/src/nextepc/webui
RUN npm install && \
    npm run build

CMD npm run start

EXPOSE 3000
