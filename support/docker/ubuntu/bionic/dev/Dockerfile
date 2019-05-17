ARG dist=ubuntu
ARG tag=latest
ARG username=nextepc
FROM ${username}/${dist}-${tag}-nextepc-base

MAINTAINER NextEPC <help@nextepc.com>

RUN apt-get update && \
    apt-get upgrade -y && \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y --no-install-recommends \
        debhelper \
        devscripts \
        dput \
        dh-autoreconf \
        dh-systemd \
        manpages-dev \
        fakeroot \
        cscope \
        vim \
        sudo \
        iputils-ping \
        wireshark \
        net-tools && \
    apt-get clean

COPY setup.sh /root

ARG username=nextepc
RUN useradd -m --uid=1000 ${username} && \
    echo "${username} ALL=(root) NOPASSWD:ALL" > /etc/sudoers.d/${username} && \
    chmod 0440 /etc/sudoers.d/${username}

WORKDIR /home/${username}
