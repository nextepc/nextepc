ARG dist=ubuntu
ARG tag=latest
ARG username=nextepc
FROM ${username}/${dist}-${tag}-nextepc-base

MAINTAINER NextEPC <help@nextepc.com>

WORKDIR /root
COPY setup.sh /root

ARG USER=nextepc
ARG REPO=nextepc
ARG BRANCH=master
RUN	git clone https://github.com/$USER/$REPO
ADD https://api.github.com/repos/$USER/$REPO/git/refs/heads/$BRANCH /root/nextepc-ver.json

RUN	cd nextepc && \
	git fetch && git checkout -f -B master origin/master && \
    autoreconf -f -i && \
    ./configure \
        --prefix=/usr \
        --sysconfdir=/etc \
        --localstatedir=/var && \
    make -j `nproc` install
